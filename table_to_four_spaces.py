import os

for path, _, files in os.walk("."):
    for fname in files:
        if fname.endswith(".py") or fname.endswith(".cpp"):
            f = os.path.join(path, fname)
            with open(f) as _f:
                data = _f.read()
            
            if "\t" in data:
                with open(f, "w") as _f:
                    _f.write(data.replace("\t", "    "))
                print ("%s changed ." % f)
