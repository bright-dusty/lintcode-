import os

for path, dirs, files in os.walk("."):
    if path == "." or path == "./":
        for dir in dirs:
            new_name = [word for word in dir.replace("-", " ").split(" ") if word.strip()]
            new_name = " ".join([word[0].upper()+word[1:] for word in new_name])
            if new_name != dir:
                os.rename(dir, new_name)
                print ("rename dir from %s to %s" % (dir, new_name))
    for fname in files:
        if fname.endswith(".py") or fname.endswith(".cpp") or fname.endswith(".c") or fname.endswith(".h"):
            f = os.path.join(path, fname)
            with open(f) as _f:
                data = _f.read()
            
            if "\t" in data:
                with open(f, "w") as _f:
                    _f.write(data.replace("\t", "    "))
                print ("%s changed ." % f)
