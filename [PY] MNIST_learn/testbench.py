import numpy as np
from mnist import load_mnist
from TwoLayerNet import TwoLayerNet
import matplotlib.pyplot as plt

(x_train, t_train), (x_test, t_test) = load_mnist(normalize = True, one_hot_label=True)

network = TwoLayerNet(784, 50, 10)

# # gradient test code

# x_batch = x_train[:3]
# t_batch = t_train[:3]
#
# testset1 = network.num_gradient(x_batch, t_batch)
# testset2 = network.back_gradient(x_batch, t_batch)
#
# for key in testset1.keys():
#     diff = np.average( np.abs(testset2[key] - testset1[key]) )
#     print(key + ":" + str(diff))

# custom parameters
iters_num = 10000
train_number = x_train.shape[0]
test_number = x_test.shape[0]
batch_number = 100
lr = 0.1

train_loss_list = []
train_acc_list = []
test_acc_list = []

#iter_per_epoch = max(train_number / batch_number, 1)

###########################################################################
# iterations

# training
for i in range(iters_num):
    process = i / iters_num * 100
    print("training process rate : {0}".format(round(process, 3), ".f") )

    batch_mask = np.random.choice(train_number, batch_number)
    x_batch = x_train[batch_mask]
    t_batch = t_train[batch_mask]

    grad = network.back_gradient(x_batch, t_batch)

    for key in ('W1', 'b1', 'W2', 'b2'):
        network.params[key] -= lr * grad[key]

    train_loss_list.append(network.loss(x_batch, t_batch))
    train_acc_list.append(network.accuracy(x_batch, t_batch))

# test
for j in range(iters_num):
    test_process = j / iters_num * 100
    print("test process rate : {0}".format(round(test_process, 3), ".2f"))
    test_mask = np.random.choice(test_number, batch_number)
    x_batch_test = x_test[test_mask]
    t_batch_test = t_test[test_mask]
    test_acc_list.append(network.accuracy(x_batch_test, t_batch_test))

#################################################################################

fig = plt.figure()
ax1 = fig.add_subplot(2, 1, 1)
ax2 = fig.add_subplot(2, 1, 2)
ax2.set_xlabel("iterations")
ax1.set_ylabel("value")
ax2.set_ylabel("accuracy rate")
ax1.plot(np.arange(iters_num), train_loss_list, label="loss")
ax2.plot(np.arange(iters_num), train_acc_list, label="train")
ax2.plot(np.arange(iters_num), test_acc_list, label="test")
ax1.legend(loc="best")
ax2.legend(loc="best")
plt.show()

# plt.xlabel("iterations")
# plt.ylabel("value")
# plt.plot(np.arange(iters_num), train_loss_list)
# plt.plot(np.arange(iters_num), train_acc_list)
# plt.plot(np.arange(iters_num), test_acc_list)
# plt.legend(['loss', 'accuracy', 'test'])
# plt.show()