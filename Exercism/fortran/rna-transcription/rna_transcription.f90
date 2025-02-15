module rna_transcription
   implicit none
contains
   function translate(c) result(r)
      character :: c, r
      select case (c)
      case ('C')
         r = 'G'
      case ('G')
         r = 'C'
      case ('T')
         r = 'A'
      case ('A')
         r = 'U'
      end select
   end function translate

   function to_rna(dna)
      integer :: i
      character(*) :: dna
      character(len(dna)) :: to_rna
      do i = 1, len(dna)
         to_rna(i:i) = translate(dna(i:i))
      end do
   end function to_rna

end module rna_transcription
