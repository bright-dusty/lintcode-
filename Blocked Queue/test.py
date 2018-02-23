from threading import Semaphore as _sem

def Queue(size):
    class _nonlocal:
        _size = 0

    _list = []
    _mutex = _sem(1)
    not_empty = _sem(0)
    not_full = _sem(size)
    
    def _get():
        with _mutex:
            _nonlocal._size -= 1
            return _list.pop(0)

    def _put(val):
        with _mutex:
            _nonlocal._size += 1
            _list.append(val)
    
    class _Queue(object):

        def get(self):
            not_empty.acquire()
            ret = _get()
            not_full.release()
            return ret

        def put(self, val):
            not_full.acquire()
            _put(val)
            not_empty.release()

        def    __str__(self):
            with _mutex:
                return "Queue(%s)" % _list
        __repr__ = __str__
        
        @property
        def qsize(self):
            return size
        
        @property
        def size(self):
            with _mutex:
                return _nonlocal._size

    return _Queue()
            
