module hamming
  implicit none
contains

  function compute(strand1, strand2, distance)
      character(*), intent(in) :: strand1, strand2
      integer, intent(out) :: distance
      integer :: i
      logical :: compute

      distance = 0
      compute = .false.
      if (len(strand1) /= len(strand2)) return

      do i = 1, len(strand1)
        if (strand1(i:i) /= strand2(i:i)) then
           distance = distance + 1
        end if
      end do

      compute = .true.
  end function compute

end module hamming
