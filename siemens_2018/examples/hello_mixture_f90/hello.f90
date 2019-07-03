program main
    use mutationpp
    implicit none
    character(len=10) :: mixture
    character(len=12) :: species, state_model
    integer :: j, ns
    
    mixture     = "air5"
    state_model = "ChemNonEq1T"
    
    ! Initialize the mutation++ library
    call mpp_initialize(mixture, state_model)
    ns = mpp_nspecies()
    
    write(*,'(A12)',advance='no') "Species: "
    do j = 1,ns
        call mpp_species_name(j, species)
        write(*,'(A12)',advance='no') species
    end do
    write(*,*)
    
    ! Clean up the memory stored in the mutation++ library
    call mpp_destroy()

end program main
