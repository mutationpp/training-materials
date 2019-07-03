program main
    use mutationpp
    implicit none
    character(len=10) :: mixture
    character(len=12) :: species, state_model
    integer :: j, ns
    integer, parameter :: set_rhoi_T = 1
    real :: Teq, Peq, T, P, rho
    real :: conv, tol, dt, time 
    real, dimension(:), allocatable :: rhoi, X, Y
    real, dimension(:), allocatable :: k1, k2, k3, k4, drhoi, W
    
    mixture     = "air5"
    state_model = "ChemNonEq1T"
    
    ! Initialize the mutation++ library
    call mpp_initialize(mixture, state_model)
    ns = mpp_nspecies()

    ! Allocate Memory
    allocate (rhoi(ns), X(ns), Y(ns))
    allocate (drhoi(ns), k1(ns), k2(ns), k3(ns), k4(ns), W(ns))
    
    ! Initial Data
    Teq = 300 !K
    Peq = 1000 !Pa
    T = 5000
    P = Peq

    ! Get our initial composition
    call mpp_equilibrium_composition(Teq, Peq, X)
    call mpp_density_tpx(Teq, Peq, X, rho)
    call mpp_convert_x_to_y(X, Y)
    rhoi = rho * Y ! Get partial densities

    ! Time integration
    tol = 1.e-13
    conv = 1.
    time = 0.
    dt = 1.e-9
    do while (conv > tol)

        ! Time step
        dt = MIN(dt * 1.0002, 1.e-5)

        ! k1
        call mpp_set_state(rhoi, T, set_rhoi_T)
        call mpp_net_production_rates(k1)

        ! k2
        W = rhoi + 0.5 * dt * k1
        call mpp_set_state(W, T, set_rhoi_T)
        call mpp_net_production_rates(k2)

        ! k3
        W = rhoi + 0.5 * dt * k2
        call mpp_set_state(W, T, set_rhoi_T)
        call mpp_net_production_rates(k3)

        ! k4
        W = rhoi + dt * k3
        call mpp_set_state(W, T, set_rhoi_T)
        call mpp_net_production_rates(k4)

        drhoi = 1./6. * dt * (k1 + 2 * k2 + 2 * k3 + k4)
        rhoi = rhoi + drhoi
    
        conv = MAXVAL(ABS(drhoi)) 
        time = time + dt
 
        print*, time, rhoi

    end do

    ! Deallocate
    deallocate (rhoi, X, Y)
    ! Clean up the memory stored in the mutation++ library
    call mpp_destroy()

end program main
