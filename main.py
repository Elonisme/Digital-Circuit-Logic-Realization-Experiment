from PyQt6 import QtWidgets, QtCore
from PyQt6.QtWidgets import (QWidget, QPushButton, QHBoxLayout, QVBoxLayout, QApplication, QTableWidgetItem)
import sys  # We need sys so that we can pass argv to QApplication
import os
import serial


from UI import Ui_MainWindow



class MainWindow(QtWidgets.QMainWindow):

    def __init__(self, *args, **kwargs):
        super(MainWindow, self).__init__(*args, **kwargs)
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        self.serial_setting()
        self.initUI()

    def serial_setting(self):
        value = self.ui.lineEdit.text()
        if len(value) == 0 :
            value = "/dev/ttyACM0"
        self.serialPort = value
        self.baudRate = 9600
        self.ser =  serial.Serial(self.serialPort,self.baudRate, timeout=1)
        
        
    def display_page1(self):
        self.ui.stackedWidget.setCurrentIndex(0)

    def display_page2(self):
        self.ui.stackedWidget.setCurrentIndex(1)

    def display_page3(self):
        self.ui.stackedWidget.setCurrentIndex(2)

    def display_page4(self):
        self.ui.stackedWidget.setCurrentIndex(3)

    def display_page5(self):
        self.ui.stackedWidget.setCurrentIndex(4)

    def display_page6(self):
        self.ui.stackedWidget.setCurrentIndex(5)

    def display_page7(self):
        self.ui.stackedWidget.setCurrentIndex(6)

    def display_page8(self):
        self.ui.stackedWidget.setCurrentIndex(7)

    def display_page9(self):
        self.ui.stackedWidget.setCurrentIndex(8)

    def display_page10(self):
        self.ui.stackedWidget.setCurrentIndex(9)

    def initUI(self):
        self.ui.pushButton_full.clicked.connect(self.display_page1)
        self.ui.pushButton_half.clicked.connect(self.display_page2)
        self.ui.pushButton_mult.clicked.connect(self.display_page3)
        self.ui.pushButton_select.clicked.connect(self.display_page4)
        self.ui.pushButton_com.clicked.connect(self.display_page5)
        self.ui.pushButton_encode.clicked.connect(self.display_page6)
        self.ui.pushButton_decode.clicked.connect(self.display_page7)
        self.ui.pushButton_select4.clicked.connect(self.display_page8)
        self.ui.pushButton_old.clicked.connect(self.display_page9)
        self.ui.pushButton_content.clicked.connect(self.display_page10)
        self.ui.pushButton.clicked.connect(self.full_add)
        self.ui.pushButton_3.clicked.connect(self.half_add)
        self.ui.pushButton_4.clicked.connect(self.majorityVoter)
        self.ui.pushButton_5.clicked.connect(self.priority_majorityVoter)
        self.ui.pushButton_6.clicked.connect(self.binaryComparator)
        self.ui.pushButton_7.clicked.connect(self.encoder)
        self.ui.pushButton_8.clicked.connect(self.decoder)
        self.ui.pushButton_9.clicked.connect(self.multi4_1)
        self.ui.pushButton_10.clicked.connect(self.parity4)
        self.ui.pushButton_2.clicked.connect(self.serial_setting)
        
    def full_add(self):
        model = "fullAdder"
        numsize = "2"
        input_A = self.ui.spinBox.value()
        input_B = self.ui.spinBox_2.value()
        order = model+" "+numsize+" "+str(input_A)+" "+str(input_B)
        self.ser.write(order.encode())
        datas = list()
        while True:
            if self.ser.in_waiting > 0:
                data = self.ser.readline().decode().strip()  # 读取并解码数据
                datas.append(data)
                print(f"Received data: {data}")
            else :
                break
        datas = datas[1:]
        self.update_table_data(datas, self.ui.table_full_add)
        self.ser.flush()

    def half_add(self):
        model = "halfAdder"
        numsize = "2"
        input_A = self.ui.spinBox_5.value()
        input_B = self.ui.spinBox_6.value()
        order = model+" "+numsize+" "+str(input_A)+" "+str(input_B)
        self.ser.write(order.encode())
        datas = list()
        while True:
            if self.ser.in_waiting > 0:
                data = self.ser.readline().decode().strip()  # 读取并解码数据
                datas.append(data)
                print(f"Received data: {data}")
            else :
                break
        datas = datas[1:]
        self.update_table_data(datas, self.ui.table_full_add_3)
        self.ser.flush()

    def majorityVoter(self):
        model = "majorityVoter"
        numsize = "3"
        input_A = self.ui.spinBox_7.value()
        input_B = self.ui.spinBox_8.value()
        input_C = self.ui.spinBox_39.value()
        
        order = model+" "+numsize+" "+str(input_A)+" "+str(input_B)+" "+str(input_C)
        self.ser.write(order.encode())
        datas = list()
        while True:
            if self.ser.in_waiting > 0:
                data = self.ser.readline().decode().strip()  # 读取并解码数据
                datas.append(data)
                print(f"Received data: {data}")
            else :
                break
        datas = datas[1:]
        self.update_table_data(datas, self.ui.table_full_add_4)
        self.ser.flush()

    def priority_majorityVoter(self):
        model = "majorityVoter4bit"
        numsize = "4"
        input_A = self.ui.spinBox_9.value()
        input_B = self.ui.spinBox_10.value()
        input_C = self.ui.spinBox_59.value()
        input_D = self.ui.spinBox_60.value()
        
        order = model+" "+numsize+" "+str(input_A)+" "+str(input_B)+" "+str(input_C)+" "+str(input_D)
        self.ser.write(order.encode())
        datas = list()
        while True:
            if self.ser.in_waiting > 0:
                data = self.ser.readline().decode().strip()  # 读取并解码数据
                datas.append(data)
                print(f"Received data: {data}")
            else :
                break
        datas = datas[1:]
        self.update_table_data(datas, self.ui.table_full_add_5)
        self.ser.flush()

    def binaryComparator(self):
        model = "binaryComparator"
        numsize = "2"
        input_A = self.ui.spinBox_11.value()
        input_B = self.ui.spinBox_12.value()
        
        order = model+" "+numsize+" "+str(input_A)+" "+str(input_B)
        self.ser.write(order.encode())
        datas = list()
        while True:
            if self.ser.in_waiting > 0:
                data = self.ser.readline().decode().strip()  # 读取并解码数据
                datas.append(data)
                print(f"Received data: {data}")
            else :
                break
        datas = datas[1:]
        self.update_table_data(datas, self.ui.table_full_add_6)
        self.ser.flush()

    def encoder(self):
        model = "encoder42"
        numsize = "4"
        input_A = self.ui.spinBox_13.value()
        input_B = self.ui.spinBox_14.value()
        input_C = self.ui.spinBox_62.value()
        input_D = self.ui.spinBox_61.value()
        
        order = model+" "+numsize+" "+str(input_A)+" "+str(input_B)+" "+str(input_C)+" "+str(input_D)
        self.ser.write(order.encode())
        datas = list()
        while True:
            if self.ser.in_waiting > 0:
                data = self.ser.readline().decode().strip()  # 读取并解码数据
                datas.append(data)
                print(f"Received data: {data}")
            else :
                break
        datas = datas[1:]
        self.update_table_data(datas, self.ui.table_full_add_7)
        self.ser.flush()

    def decoder(self):
        model = "decoder24"
        numsize = "2"
        input_A = self.ui.spinBox_15.value()
        input_B = self.ui.spinBox_16.value()
        
        order = model+" "+numsize+" "+str(input_A)+" "+str(input_B)
        self.ser.write(order.encode())
        datas = list()
        while True:
            if self.ser.in_waiting > 0:
                data = self.ser.readline().decode().strip()  # 读取并解码数据
                datas.append(data)
                print(f"Received data: {data}")
            else :
                break
        datas = datas[1:]
        self.update_table_data(datas, self.ui.table_full_add_8)
        self.ser.flush()

    def multi4_1(self):
        model = "multi4_1"
        numsize = "6"
        input_A = self.ui.spinBox_17.value()
        input_B = self.ui.spinBox_18.value()
        input_C = self.ui.spinBox_63.value()
        input_D = self.ui.spinBox_64.value()
        S0 = self.ui.spinBox_92.value()
        S1 = self.ui.spinBox_93.value()
        
        order = model+" "+numsize+" "+str(input_A)+" "+str(input_B)+" "+str(input_C)+" "+str(input_D)+" "+str(S0)+" "+str(S1)
        self.ser.write(order.encode())
        datas = list()
        while True:
            if self.ser.in_waiting > 0:
                data = self.ser.readline().decode().strip()  # 读取并解码数据
                datas.append(data)
                print(f"Received data: {data}")
            else :
                break
        datas = datas[1:]
        self.update_table_data(datas, self.ui.table_full_add_9)
        self.ser.flush()

    def parity4(self):
        model = "parity4"
        numsize = "4"
        input_A = self.ui.spinBox_19.value()
        input_B = self.ui.spinBox_20.value()
        input_C = self.ui.spinBox_90.value()
        input_D = self.ui.spinBox_91.value()
        
        order = model+" "+numsize+" "+str(input_A)+" "+str(input_B)+" "+str(input_C)+" "+str(input_D)
        self.ser.write(order.encode())
        datas = list()
        while True:
            if self.ser.in_waiting > 0:
                data = self.ser.readline().decode().strip()  # 读取并解码数据
                datas.append(data)
                print(f"Received data: {data}")
            else :
                break
        datas = datas[1:]
        self.update_table_data(datas, self.ui.table_full_add_10)
        self.ser.flush()
        
        
    def update_table_data(self, dates, table):
        new_data = dates
        for row, rowData in enumerate(new_data):
            for col, itemData in enumerate(rowData):
                # 使用setItem()方法更新单元格数据
                item = QTableWidgetItem(itemData)
                table.setItem(row, col, item)


def main():
    app = QtWidgets.QApplication(sys.argv)
    w = MainWindow()
    w.show()
    sys.exit(app.exec())


if __name__ == '__main__':
    main()
