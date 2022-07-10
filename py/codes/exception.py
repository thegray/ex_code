def raising_python_exception(x, y):
    try:
        z = x/y
    except (ZeroDivisionError, e):
        err = e
    print (e)

raising_python_exception(1,0)