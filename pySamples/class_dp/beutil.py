
def capfirst(text):
    c = text[0]
    if c >='a' and c<='z':
        text = chr(ord(c) - ord('a') + ord('A')) + text[1:]
    return text
