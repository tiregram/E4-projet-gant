from Xlib.display import Display, X




def printWindowHierrarchy(window, indent):
    children = window.query_tree().children
    for w in children:
        # if w.get_wm_clasas() is not None:
        print(w.id, indent, w.get_wm_name(), w.get_wm_class())
        get_pixmap(w)

def get_pixmap(win):
    el = win.get_geometry()

    x=el.x
    y=el.y
    w=el.width
    h= el.height

    img = win.get_image(x, y, w, h, X.XYPixmap, 0xffffffff)

    print(dir(img))
    print(img._binary)


display = Display(":8")
root = display.screen().root
printWindowHierrarchy(root, '-')
