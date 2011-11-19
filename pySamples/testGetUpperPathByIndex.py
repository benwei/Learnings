import os

def dirnameWithLayer(srcPath, index):
    rPath=os.path.dirname(srcPath)
    index -= 1
    if index >= 0:
        return dirnameWithLayer(rPath, index)
    return rPath

print dirnameWithLayer(os.path.abspath(__file__), 3)


