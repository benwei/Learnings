import uuid

class ShortUUID():
    def __init__(self):
        pass

    def uuid4(self):
        return str(uuid.uuid4())[:8].upper()


su = ShortUUID()
short_uuid = su.uuid4()

print("short_uuid = %s" % short_uuid)
