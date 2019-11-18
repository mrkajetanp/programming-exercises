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


from collections import defaultdict
track_table = defaultdict(int)

def reset_tracking():
    track_table.clear()
    
def verify_track(code):
    sha = sha1(str(track_table.items()).encode('utf8')).hexdigest()[0:8]
    print(sha)
    assert sha == code
    
def fail_if_debug():
    debugging = any(['bdb' in f.filename for f in inspect.getouterframes(inspect.currentframe())])
    if debugging or sys.gettrace() is not None:
        display(HTML('<marquee> <div class="alert alert-box alert-danger"> <h1> Hey, I told you not to use the debugger </h1> </div> </marquee>'))
        raise Exception("User cannot follow instructions")                             
    
def track(fn):
    track_table[fn.__name__] = 0
    def wrapped_fn(*args, **kwargs):
        fail_if_debug()
        track_table[fn.__name__] = 1
        return fn(*args, **kwargs)
    return wrapped_fn    