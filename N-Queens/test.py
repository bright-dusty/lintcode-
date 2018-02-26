from copy import copy
from ctypes import c_char

class rows(list):
    def __init__(self, n):
        if isinstance(n, list):
            super(rows, self).__init__(n)
        else:
            super(rows, self).__init__()
            self._avail = set(range(n))
        self._sub = set()
        self._plus = set()
        
    def __contains__(self, col):
        if len(self) + col in self._plus:
            return True
        if len(self) - col in self._sub:
            return True
        return False
        
    def append(self, col):
        self._plus.add(len(self) + col)
        self._sub.add(len(self) - col)
        super(rows, self).append(col)
        self._avail.remove(col)
    
    @property
    def avail(self):
        return self._avail
        
    def copy(self):
        _rows = rows(self)
        _rows._sub = copy(self._sub)
        _rows._plus = copy(self._plus)
        _rows._avail = copy(self._avail)
        return _rows
        

def solveNQueens(n):
    solv = list()
    for col in range(n):
        _rows = rows(n)
        _rows.append(col)
        solv.append(_rows)
    solutions = list()
    while len(solv):
        _rows = solv.pop()
        if len(_rows) == n:
            solution = list()
            for col in _rows:
                row = (c_char * n)()
                for _col in range(n):
                    row[_col] = '.'
                row[col] = 'Q'
                solution.append(row.value)
            solutions.append(solution)
                
        for col in _rows.avail:
            if col not in _rows:
                _new_row = _rows.copy()
                _new_row.append(col)
                solv.append(_new_row)
    return solutions

    
print len(solveNQueens(13))
    