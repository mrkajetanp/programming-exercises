module difference_of_squares
   implicit none
contains

   integer function square_of_sum(n)
      integer :: n, i
      integer, dimension(n) :: arr
      arr = (/(i, i=1, n)/)
      square_of_sum = sum(arr)**2
   end function square_of_sum

   integer function sum_of_squares(n)
      integer :: n, i
      integer, dimension(n) :: arr
      arr = (/(i**2, i=1, n)/)
      sum_of_squares = sum(arr)
   end function sum_of_squares

   integer function difference(n)
      integer :: n
      difference = square_of_sum(n) - sum_of_squares(n)
   end function difference

end module difference_of_squares
