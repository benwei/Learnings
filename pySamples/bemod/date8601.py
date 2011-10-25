#!/usr/bin/env python
import datetime
FMT8601String = "%Y-%m-%dT%H:%M:%SZ"
class Date8601:
    def __init__(self, strDatetime):
        self.date = self.fromString(strDatetime)

    def fromString(self, strDatetime):
        return datetime.datetime.strptime( strDatetime, FMT8601String)

    def to8601String(self):
        return self.date.strftime(FMT8601String)
    def addDelta(self, sourceSeconds):
        self.date = self.date - datetime.timedelta(seconds=sourceSeconds)
        return self.date

