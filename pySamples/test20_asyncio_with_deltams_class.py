#!/usr/bin/env python3
import asyncio
from time import time, time_ns

class DeltaMS:
    def __init__(self):
        self.startms = self.millis();
    def millis(self):
        return round(time() * 1000)

    def delta(self):
        return self.millis() - self.startms

class DeltaNS:
    def __init__(self):
        self.startns = self.ns();

    def ns(self):
        return time_ns()

    def delta(self):
        return self.ns() - self.startns

# tested on m1 macos 12.4, Python 3.9.13
async def main():
    print('Before asyncio sleep 1.5 ...')
    d = DeltaMS()
    await asyncio.sleep(1.5)
    ms = d.delta()
    print('... after asyncio.sleep 1.5! spent %u ms' % (ms))
    print('Before asyncio sleep 1.5 ...')
    ns = DeltaNS()
    await asyncio.sleep(0.01)
    ns = ns.delta()
    us = ns / 1000
    ms = us / 1000.0
    print('... after asyncio.sleep 0.01! spent %u ns, %u us, %.2f ms' % (ns, us, ms))

if __name__ == '__main__':
    asyncio.run(main())
