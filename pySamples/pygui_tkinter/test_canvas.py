import time

import tkinter as tk
from tkinter import ttk


class MockDataSource():
    def __init__(self):
        self.index = 0
        self.data = [  53,   53,   53,   53,    53,   53,   53,   56,   53,   54,   59,  70,
                       83,  100,  128,   155,  187,  226,  263,  304,  344,  388,  432, 476,
                      525,  569,  616,   661,  703,  748,  792,  833,  873,  914,  953, 990,
                     1027, 1060, 1094, 1123, 1154, 1183, 1210, 1235, 1261, 1283, 1306, 1329,
                     1349, 1374, 1392, 1412, 1429, 1439, 1446, 1445, 1435, 1414, 1383, 1341,
                     1286, 1225, 1154, 1076,  993,  905,  817,  724,  634,  545,  461,  380,
                      297,  213,  162,   89,   70,   59,   54,   53,   53,   53,   53,   53]
        self.datalen = len(self.data)

    def next(self):
        self.index= (self.index + 1) % self.datalen
        return self.data[self.index-1]


class HeartbeatApp(tk.Tk):

    def __init__(self, *args, **kwargs):

        tk.Tk.__init__(self, *args, **kwargs)

        tk.Tk.wm_title(self, "Ben Test with Canvas")

        container = tk.Frame(self, width=800, height=600)
        container.pack(side="top", fill="both", expand = True)
        container.grid_rowconfigure(0, weight=1)
        container.grid_columnconfigure(0, weight=1)
        self.mockdata = MockDataSource()
        self.frames = {}
        self.activeFrame = {}

        for F in [DrawPage]:
            frame = F(container, self)
            self.frames[F] = frame
            frame.grid(row=0, column=0, sticky="nsew")

        self.show_frame(DrawPage)
        self.update_clock()
        self.mainloop()

    def show_frame(self, cont):
        frame = self.frames[cont]
        self.activeFrame = frame
        frame.tkraise()

    def update_clock(self):
        # use label to display time, but abnormal flash,
        # tested with another method by canvas.create_text is much better.
        now = time.strftime("%H:%M:%S")
        self.activeFrame.label_clock.configure(text=now)
        self.activeFrame.add(self.mockdata.next())
        self.after(1, self.update_clock)

LARGE_FONT= ("Courier", 12)

class DrawPage(tk.Frame):
    maxwidth = 800
    maxheight= 600
    width = 640
    height = 480
    def __init__(self, parent, controller):
        tk.Frame.__init__(self,parent)
        label = tk.Label(self, text="Heartbeat", font=LARGE_FONT)
        label.pack(pady=10,padx=10)

        self.label_clock = tk.Label(text="----")
        self.label_clock.pack(pady=1, padx=1)

        self.offset = 50
        self.top    = 50
        self.x1 = 100
        self.y1 = 100
        self.c = tk.Canvas(self, width=self.maxwidth, height=self.maxheight, bg="white")
        self.c.place(x=10, y=10)
        self.c.pack()
        self.c.create_rectangle(10, 10, self.maxwidth,self.height, width=1)
        self.mytext = self.c.create_text(self.maxwidth/2 - 5,self.height+10,fill="darkblue",font="Times 20 italic bold",
                                text="000")

    def draw(self, y):
        self.x2, self.y2 = self.x1 + 1, y
        self.c.create_rectangle(self.x1 + self.offset+6, self.top+2,
                                self.x2 + self.offset+6, self.height-1, width=0, fill="white")
        self.c.create_line(self.x1 + self.offset , self.top + self.y1,
                           self.offset + self.x2, self.top + self.y2, fill="red", width = 2)
        self.x1, self.y1 = self.x2, self.y2
        if self.x1 > self.width:
            self.x1 = 0
            self.c.create_rectangle(self.offset-6, 12, self.offset+6, self.height-1, width=0, fill="white")
        now = time.strftime("%H:%M:%S")
        self.c.itemconfigure(self.mytext, text=now)

        self.c.update()

    def add(self, y):
        self.draw(y/4)

def main():
    app = HeartbeatApp()

main()
