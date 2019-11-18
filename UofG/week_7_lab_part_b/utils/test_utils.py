def should_fail(test_fn, *args, **kwargs):
    try:
        test_fn(*args, **kwargs)
    except AssertionError:
        return True
    except Exception:		
        return True
    raise AssertionError("Test passed but should not have!")
    
def should_pass(test_fn, *args, **kwargs):
    try:
        test_fn(*args, **kwargs)
    except AssertionError:
        raise AssertionError("Test did not pass but should have!")    
    return True

from hashlib import sha1
import sys
from IPython.display import display, HTML
import inspect
import timeit
import base64
import io

def test_dups(remove_duplicates):
    exec(base64.b64decode(b'CmFzc2VydCByZW1vdmVfZHVwbGljYXRlcyhbXSk9PVtdICMgZW1wdHkKYXNzZXJ0IHJlbW92ZV9kdXBsaWNhdGVzKFsxLCAxLCAyLCAzLCA1LCA2LCA2LCA2LCA5LCAxLCAyXSkgPT0gWzEsIDIsIDMsIDUsIDYsIDksIDEsIDJdCmFzc2VydCByZW1vdmVfZHVwbGljYXRlcyhbTm9uZV0pPT1bXSAjIE5vbmUKYXNzZXJ0IHJlbW92ZV9kdXBsaWNhdGVzKFtOb25lLCBOb25lXSk9PVtdICMgTm9uZQphc3NlcnQgcmVtb3ZlX2R1cGxpY2F0ZXMoWzFdKT09WzFdICMgc2luZ2xlCmFzc2VydCByZW1vdmVfZHVwbGljYXRlcyhbMSwgMV0pPT1bMV0gIyBzaW5nbGUgZHVwbGljYXRlCmFzc2VydCByZW1vdmVfZHVwbGljYXRlcyhbMSwgMywgMV0pPT1bMSwgMywgMV0gIyBlZGdlLXdyYXAKYXNzZXJ0IHJlbW92ZV9kdXBsaWNhdGVzKFsyLDEsMV0pPT1bMiwxXSAjIHNpbmdsZSBmb2xsb3dlZCBieSBkdXAuCmFzc2VydCByZW1vdmVfZHVwbGljYXRlcyhbMiwyLDFdKT09WzIsIDFdICMgZHVwLiBmb2xsb3dlZCBieSBzaW5nbGUKYXNzZXJ0IHJlbW92ZV9kdXBsaWNhdGVzKFsyLDIsMSwxLDIsMl0pPT1bMiwxLDJdICMgdHdvIGR1cAphc3NlcnQgcmVtb3ZlX2R1cGxpY2F0ZXMoWzEsMSwgMiwyLCAzLDNdKT09WzEsMiwzXSAjIHRocmVlIGR1cCwgc2VwYXJhdGVkCmFzc2VydCByZW1vdmVfZHVwbGljYXRlcyhbMSwxLDFdKT09WzFdICMgdHJpcGxlCmFzc2VydCByZW1vdmVfZHVwbGljYXRlcyhbOSw5LDksOSw5XSk9PVs5XSAjIHF1YWQKYXNzZXJ0IHJlbW92ZV9kdXBsaWNhdGVzKFs5LCJhIiw5LDksOV0pPT1bOV0gIyBub24tZGlnaXQKYXNzZXJ0IHJlbW92ZV9kdXBsaWNhdGVzKFs5LCJhIiw5LDksImEiXSk9PVs5XSAjIG5vbi1kaWdpdAphc3NlcnQgcmVtb3ZlX2R1cGxpY2F0ZXMoWzksImEiLDksOSwiYSIsOV0pPT1bOV0gIyBub24tZGlnaXQKYXNzZXJ0IHJlbW92ZV9kdXBsaWNhdGVzKFs5LCIzIiwxLDEsIjIiLDldKT09WzksMSw5XSAjIG5vbi1kaWdpdAphc3NlcnQgcmVtb3ZlX2R1cGxpY2F0ZXMoWyJhIl0pPT1bXSAjIG5vbi1kaWdpdAo=').decode("ascii"))


def factorise(number):
    candidates =[]    
    for i in range(2, number+1):
        # is it divisible? if so append it
        if number%i==0:
            candidates.append(i)
            
    return candidates

def _crack_the_code_slow():
    # This code will generate test sequences for the defuser.
    #
    # We know that the pattern involves factorising one of 100
    # secret numbers that we have in the file secret_numbers.txt
    #
    # The code to be generated is the digits of each unique prime
    # factor of one of the numbers, all joined into one string
    #
    # We just don't know which one produces the right code, so
    # we can test them all.
    decodes = []
    
    digit_sequence = ""
    # test all 15 numbers
    for i in range(15):
        print(i, end=" ")
        # read in th numbers
        with open("secret_numbers.txt") as f:
            for j, line in enumerate(f):
                # find the right line for this number
                if i==j:
                    n = int(line) # convert to integer
                    
        primes = []
        
        # compute the prime numbers
        for i in range(10_000):
            candidates = factorise(i)
            # is it prime (has no factors other than 1 and itself?)
            if len(candidates)==1:
                primes = primes + [i]
        
        # now factor the number
        factors = factorise(n)
        prime_factors = []
        for factor in factors:
            # only keep prime factors
            if factor in primes:
                prime_factors.append(factor)
                
        # now build the string up        
        for factor in prime_factors:
            # add the string version of each digit
            digit_sequence = digit_sequence + str(factor)
            
                         

    return digit_sequence


def test_execution_time(slow, fast):
    
    base_time = timeit.timeit("slow()", globals={"slow":slow}, number=1)
    fast_time = timeit.timeit("fast()", globals={"fast":fast}, number=1)

    ratio = base_time / fast_time
    return ratio


def report_execution_time(fast):

    ratio = test_execution_time(_crack_the_code_slow, fast)
    print()
    print("Speed ratio: {ratio:.1f}x faster".format(ratio=ratio))

    if ratio>2 and ratio<5:
        print("A little faster, but way too slow")
        boom()
    
    if ratio>5 and ratio<10:
        print("Faster, but not fast enough")
        boom()
    if ratio>10 and ratio<100:
        print("10x faster, but the bomb will still relock")
        boom()
    if ratio>100 and ratio<1000:
        print("100x faster, still too slow")
        boom()
    if ratio>1000 and ratio<5000:
        print("More than 1000x faster, unlocked in time!")
    if ratio>5000:
        print("More than 5000x faster, good job!")



from collections import defaultdict
track_table = defaultdict(int)

def begin_defusal():
    track_table.clear()

import random, time

def set_colour(hex_color):
    javascript = """<script type="text/Javascript">var dom_site = document.getElementById('site'); dom_site.style.backgroundColor = '{color}';  </script>""".format(
        color=hex_color
    )
    display(HTML(javascript))



def boom(shake_times=2, duration=0.15, p=0.5):
    display(HTML(("<h1> BOOM! </h1>")))
    # randomly detonate visually
    if random.random()>p:        
        return 

    boom_colours = ["#ff8800", "#dd3300", "#111111", "#ffee90", "#fffed0"]    
    display(HTML(f"""
    <script>
      $( "#site" ).effect( "shake", {{direction:"up", times:{shake_times}, distance:30}} );
    </script>    
    """))

    if p==1.0:
        display(HTML("""
        
        <div class="boom">
        <img src="imgs/cat.gif">
        </div>
        """))

    for i in range(5):
        time.sleep(0.05)
        set_colour(random.choice(boom_colours))
    time.sleep(0.25)
    set_colour("#ffffff")
    time.sleep(duration)
    display(HTML("""
    <script>
      $( ".boom" ).hide();
    </script>    
    """))


def short_hash(v):
    sha = sha1(str(v).encode('utf8')).hexdigest()[0:8]
    return sha

def defuse(code):
    sha = short_hash(track_table.items())
    print(sha)
    if sha != code:
        boom()

    assert sha == code
    
def fail_if_debug():
    debugging = any(['bdb' in f.filename for f in inspect.getouterframes(inspect.currentframe())])
    if debugging or sys.gettrace() is not None:
        display(HTML('<marquee> <div class="alert alert-box alert-danger"> <h1> Hey, I told you not to use the debugger </h1> </div> </marquee>'))
        boom(shake_times=5, duration=10.5, p=1.0)
        raise Exception("User cannot follow instructions, cat detonated.")        

    
def detonate(should_detonate):
    def track(fn):
        track_table[fn.__name__] = 0
        def wrapped_fn(*args, **kwargs):
            if should_detonate:
                boom()
                assert False
                
            fail_if_debug()        
            track_table[fn.__name__] = 1
            return fn(*args, **kwargs)
        return wrapped_fn    
    return track