
module acronym
  implicit none
contains
  character function to_upper(c)
    character, intent(in) :: c
    to_upper = c
    if (ichar(c) >= ichar('a') .and. ichar(c) < ichar('z')) then
       to_upper = char(ichar(c) - 32)
    end if
  end function

  function abbreviate(s)
    character(len=*), intent(in) :: s
    character(len=len_trim(s)) :: abbreviate, temp
    integer :: i, start, pos
    abbreviate = ""
    temp = s

    ! Remove punctuation
    do i = 1, len_trim(temp)
       if (temp(i:i) == '-' .or. temp(i:i) == '_') then
         temp(i:i) = ' '
       end if
    end do

    start = 1
    do while (start < len_trim(temp))
       pos = scan(temp(start:), " ")
       abbreviate = trim(abbreviate) // to_upper(temp(start:start))
       if (pos == 0) then ! last word
          exit
       else
          start = start + pos
       end if
    end do

  end function

end module
