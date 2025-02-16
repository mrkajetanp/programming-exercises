module pangram
  implicit none
contains

  integer function get_idx(char)
    character, intent(in) :: char

    get_idx = 0
    if (ichar(char) >= ichar('a') .and. ichar(char) <= ichar('z')) then
       get_idx = ichar(char) - ichar('a') + 1
    end if
    if (ichar(char) >= ichar('A') .and. ichar(char) <= ichar('Z')) then
       get_idx = ichar(char) - ichar('A') + 1
    end if
  end function get_idx

  logical function is_pangram(sentence)
    character(*) :: sentence
    integer :: idx, i
    integer :: letters(26)
    letters = 0

    do i = 1, len_trim(sentence)
       idx = get_idx(sentence(i:i))
       if (idx > 0) then
          letters(idx) = letters(idx) + 1
       end if
    end do

    print *, letters
    is_pangram = (.not. any(letters == 0))
   end function is_pangram

end module pangram
