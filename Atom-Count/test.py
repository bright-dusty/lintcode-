from collections import OrderedDict

import re as _re

def parse(text):
    result = [[ele for ele in item if ele] for item in _re.findall("(\(.*\))(\d*)|([A-Z][a-z]*)(\d*)", text)]
    _dict = {}
    for item in result:
        if len(item) == 1:
            cnt = 1
        else:
            cnt = int(item[1])
        if item[0].startswith("("):
            sub = parse(item[0][1:-1])
            for _key in sub:
                _cnt = sub[_key] * cnt
                if _key not in _dict:
                    _dict[_key] = _cnt
                else:
                    _dict[_key] += _cnt
        else:
            if item[0] not in _dict:
                _dict[item[0]] = cnt
            else:
                _dict[item[0]] += cnt
    return OrderedDict(sorted(_dict.items(), key=lambda item:item[0]))


print parse("K4(ON(SO3)2)2"), parse("Mg(OH)2")
    