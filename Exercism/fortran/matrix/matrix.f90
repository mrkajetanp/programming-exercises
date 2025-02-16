module matrix
  implicit none

contains

  function row(matrix, dims, i) result(r)
    integer, dimension(2), intent(in) :: dims
    !! Matrix dimensions (nrows, ncols)
    character(len=*), dimension(dims(1)), intent(in) :: matrix
    !! Matrix as a 1-d array of strings
    integer, intent(in) :: i
    integer :: j, start, pos, x
    !! Row index
    integer, dimension(dims(2)) :: r
    character(100) :: temp
    r(:) = 0
    temp = matrix(i)
    start = 1
    do j = 1, dims(2)
       pos = scan(temp(start:), ",")
       if (pos == 0) then
          read(temp(start:), *) x
       else
          read(temp(start:start+pos-2), *) x
       end if

       r(j) = x
       start = start + pos
    end do
  end function

  function column(matrix, dims, j) result(c)
    integer, dimension(2), intent(in) :: dims
    !! Matrix dimensions (nrows, ncols)
    character(len=*), dimension(dims(1)), intent(in) :: matrix
    !! Matrix as a 1-d array of strings
    integer, intent(in) :: j
    !! Column index
    integer, dimension(dims(1)) :: c
    integer :: i, k, start, pos, x
    character(100) :: temp
    c(:) = 0

    ! Iterate over rows
    do i = 1, dims(1)
       temp = matrix(i)

       start = 1
       do k = 1, dims(2)
          pos = scan(temp(start:), ",")
          if (k == j) then
            if (pos == 0) then
              read(temp(start:), *) x
            else
              read(temp(start:start+pos-2), *) x
            end if
            c(i) = x
            exit
          end if
          start = start + pos
       end do
    end do

  end function

end module
