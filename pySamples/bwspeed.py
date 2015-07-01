import datetime

class BWSpeed():
    def __init__(self):
        self.start = datetime.datetime.now()

    def escaped(self):
        self.end = datetime.datetime.now()

        self.delta = self.end - self.start;
        return self.delta.microseconds
