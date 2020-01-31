import numpy as np
from Error import *

class Mullayer:
    def __init__(self):
        self.x, self.y = none

    def forward(self, x, y):
        self.x = x
        self.y = y
        return x * y

    def backward(self, upperflow):
        return self.y * upperflow, self.x * upperflow

class Addlayer:
    def __init__(self):
        pass

    def forward(self, x, y):
        return x + y

    def backward(self, upperflow):
        return upperflow, upperflow

class ReLU:
    def __init__(self):
        self.mask = None

    def forward(self, x):
        self.mask = (x <= 0) # boolean list 저장, 조건에 해당될 시 filter 기능 ON됨
        out = x.copy() # define out variable
        out[self.mask] = 0 # filtering 해야되는 인덱스 모조리 0으로 세팅
        return out

    def backward(self, upperflow):
        upperflow[self.mask] = 0
        return upperflow

class sigmoid:
    def __init__(self):
        self.y = none

    def forward(self, x):
        self.y = 1 / (1 + np.exp(-x))
        return self.y

    def backward(self, upperflow):
        return self.y * (1 - self.y) * upperflow

class Affine:
    def __init__(self, W, b):
        self.W = W
        self.b = b
        self.x = None # self input
        self.dW = None # gradient Weight
        self.db = None # gradient bias

    def forward(self, x):
        self.x = x
        out = np.dot(x, self.W) + self.b
        return out

    def backward(self, dout):
        dx = np.dot(dout, self.W.T) # Weight Transpose
        self.dW = np.dot(self.x.T, dout)
        self.db = np.sum(dout, axis = 0)

        return dx

class SoftmaxWithLoss:
    def __init__(self):
        self.loss = None
        self.y = None
        self.t = None # 정답 레이블, One hot encoding

    def forward(self, x, t):
        self.t = t
        self.y = Softmax(x)
        self.loss = CEE(self.y, self.t)
        return self.loss

    def backward(self, dout=1):
        batch_size = self.t.shape[0]
        dx = (self.y - self.t) / batch_size
        return dx