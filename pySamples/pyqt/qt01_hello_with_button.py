#! /usr/local/bin/python
# -*- coding: utf-8 -*-
# note: tested on osx 10.10.5
# osx install pyqt
# execute the following brew command to install pyqt
# `brew install pyqt`

import sys
from PyQt4.QtGui import *

app = QApplication(sys.argv)

# defines window title string
TITLE = "Hello World!"

class Window(QWidget):
    def __init__(self):
        self.counter = 1;
        QWidget.__init__(self)

        # window size minimum
        self.setMinimumSize(320, 240)

        self.setWindowTitle(TITLE)
        self.button = QPushButton('Increase Counter', self)
        self.button.clicked.connect(self.handleButton)
        layout = QVBoxLayout(self)
        layout.addWidget(self.button)
        self.label = QLabel('label', self)
        self.label.setText('This is a testing label')
        layout.addWidget(self.label)

    def handleButton(self):
        self.label.setText('Hello World, click %d times.' % self.counter)
        self.counter+=1;

def main():
    # The QWidget widget is the base class of all user interface objects in PyQt4.
    w = Window()
    w.show()

    sys.exit(app.exec_())

if __name__ == "__main__":
    main()
