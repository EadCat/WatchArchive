from Error import *
from node import *
from collections import OrderedDict
import numpy as np

class TwoLayerNet:
    def __init__(self, input_size, hidden_size, output_size, weight_init_std = 0.01):
        #setting parameters in Networks
        self.params = {}
        self.params['W1'] = weight_init_std * np.random.randn(input_size, hidden_size)
        self.params['b1'] = np.zeros(hidden_size)
        self.params['W2'] = weight_init_std * np.random.randn(hidden_size, output_size)
        self.params['b2'] = np.zeros(output_size)

        # internal layer making
        self.layers = OrderedDict()
        self.layers['Affine1'] = Affine(self.params['W1'], self.params['b1'])
        self.layers['ReLU1'] = ReLU()
        self.layers['Affine2'] = Affine(self.params['W2'], self.params['b2'])
        self.lastlayer = SoftmaxWithLoss()

    # prediction method
    def predict(self, x):
        for layer in self.layers.values():
            x = layer.forward(x)

        return x

    # Softmax loss function
    def loss(self, x, t):
        y = self.predict(x)
        return self.lastlayer.forward(y, t)

    # Utility
    def accuracy(self, x, t):
        y = self.predict(x)
        y = np.argmax(y, axis=1)
        if t.ndim != 1 : t = np.argmax(t, axis=1)

        result = np.sum(y == t) / float(x.shape[0])
        return result

    # numerical grad_ calling function
    def gradient(self, f, x):
        h = 1e-4  # 0.0001
        grad = np.zeros_like(x)

        it = np.nditer(x, flags=['multi_index'], op_flags=['readwrite'])
        # x 는 gaussian 정규분포 size:(2,3), weight값임.
        while not it.finished:
            idx = it.multi_index
            tmp_val = x[idx]  # x[(0, 0)] ~ x[(1, 2)]
            x[idx] = float(tmp_val) + h
            fxh1 = f(x)  # f(x+h)

            x[idx] = tmp_val - h
            fxh2 = f(x)  # f(x-h)
            grad[idx] = (fxh1 - fxh2) / (2 * h)  # weight의 미분값을 얻음

            x[idx] = tmp_val  # 값 복원
            it.iternext()

        return grad

    # numerical gradient extraction function
    def num_gradient(self, x, t):
        loss_W = lambda W: self.loss(x, t)
        grad = {}

        grad['W1'] = self.gradient(loss_W, self.params['W1'])
        grad['b1'] = self.gradient(loss_W, self.params['b1'])
        grad['W2'] = self.gradient(loss_W, self.params['W2'])
        grad['b2'] = self.gradient(loss_W, self.params['b2'])

        return grad

    # back propagation algorithm function
    def back_gradient(self, x, t):
        # forward
        self.loss(x, t)

        # backward
        dout = 1
        dout = self.lastlayer.backward(dout)

        layers = list(self.layers.values())
        layers.reverse() # using OrderedDictionary
        for layer in layers:
            dout = layer.backward(dout)

        grads = {}
        grads['W1'] = self.layers['Affine1'].dW
        grads['b1'] = self.layers['Affine1'].db
        grads['W2'] = self.layers['Affine2'].dW
        grads['b2'] = self.layers['Affine2'].db

        return grads