int invert(int a)
{
	int x;
	x = (a==0)?(1):(0);
	return x;
}

void parity4(int a, int b,int c, int d, int *y1)
{
  *y1 = a ^ b ^ c ^ d;
}

void encoder42(int a, int b,int c, int d, int *y1, int *y2)
{
  int str[4] = {0};
  str[3] = a;
  str[2] = b;
  str[1] = c;
  str[0] = d; 
  int j = 0;
  for (int i = 0; i < 4; i++)
  {
    if(str[i] == 1)
      j++;
        
  }

  if (j == 1)
  {
    *y1 = (invert(a) & invert(b) & c & invert(d)) | (invert(a) & invert(b) & invert(c) & d);
    *y2 = (invert(a) & b & invert(c) & invert(d)) | (invert(a) & invert(b) & invert(c) & d);
  }
  else{
    *y1 = -1;
    *y2 = -1;
  }
}

void decoder24(int a, int b, int *y1, int *y2, int *y3, int *y4)
{
  *y1 = invert(a) & invert(b);
  *y2 = invert(a) & b;
  *y3 = a & invert(b);
  *y4 = a & b;
}

/*
  4选1多路选择器，即从输入的四个数据中选择其中一个。
  通过定义两个变量，产生四种状态，分别对应四个数据的输出。
  由此可得到如下真值表。将输入的a,b,c,d(待选),s1,s2（选择信号）和输出y1的关系写成逻辑表达式则得到：
  y=x1(a’b’)+x2(a’b)+x3(ab’)+x4(ab)
*/
void multi4_1(int a, int b, int c, int d, int s1, int s2, int *y1)
{
  *y1 = (a & (invert(s1) & invert(s2))) | (b & (invert(s1) & b)) | (c & (s1 & invert(s2))) | (d & (s1 & s2));
}

// 定义全加器函数
void fullAdder8(int a, int b, int *sum, int *carry) {
  int bin_a[8], bin_b[8];
  for (int i = 7; i >= 0; i--) {
    bin_a[i] = a % 2;
    a /= 2;
  }
  for (int i = 7; i >= 0; i--) {
    bin_b[i] = b % 2;
    b /= 2;
  }

  *carry = 0;
  for (int i = 7; i >= 0; i--) {
    sum[i] = bin_a[i] ^ bin_b[i] ^ *carry;  // 计算和
    *carry = (bin_a[i] & bin_b[i]) | (*carry & (bin_a[i] ^ bin_b[i]));  // 计算进位
  }
}

void halfAdder(int a, int b, int *sum, int *carry) {
  *sum = a ^ b;      // 通过异或操作计算和
  *carry = a & b;    // 通过与操作计算进位
}


int majorityVoter(int a, int b, int c) {
  int sum = a + b + c;
  if (sum >= 2) {
    return 1;
  } else {
    return 0;
  }
}

void binaryComparator(int a, int b, int result[3]) {
  result[0] = (a > b) ? 1 : 0;
  result[1] = (a < b) ? 1 : 0;
  result[2] = (a == b) ? 1 : 0;
}

int majorityVoter4bit(int a, int b, int c, int d) {
  int win = 0, lose = 0;
  if(a == 1){
    win = win + 2;
  }else{
    lose = lose+2;
  }
  if(b == 1){
    win = win + 1;
  }else{
    lose = lose+1;
  }
  if(c == 1){
    win = win + 1;
  }else{
    lose = lose+1;
  }
  if(d == 1){
    win = win + 1;
  }else{
    lose = lose+1;
  }
  
  if (win >= lose) {
    return 1;
  } else {
    return 0;
  }
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    String receivedData = Serial.readStringUntil('\n'); // 读取串口中的数据直到遇到换行符 '\n'
    receivedData.trim(); // 去除首尾的空白字符
    Serial.println(receivedData);

     // 解析数据
    String strData;
    int arraySize;
    int intArray[10] = {0}; // 假设数组的最大大小为10，根据需求调整

    // 使用 indexOf() 函数获取各部分数据的位置
    int spaceIndex1 = receivedData.indexOf(' ');
    int spaceIndex2 = receivedData.indexOf(' ', spaceIndex1 + 1);
    int spaceIndex3 = receivedData.indexOf(' ', spaceIndex2 + 1);

    // 提取字符串数据
    strData = receivedData.substring(0, spaceIndex1);
    // 提取数组大小
    arraySize = receivedData.substring(spaceIndex1 + 1, spaceIndex2).toInt();

    // 使用循环提取整数数据并存储到整数数组中
    for (int i = 0; i < arraySize; i++) {
      int startIndex = spaceIndex2;
      int endIndex = spaceIndex3;

      // 使用 substring() 函数提取整数数据并转换为整数类型
      intArray[i] = receivedData.substring(startIndex + 1, endIndex).toInt();

      spaceIndex2 = endIndex;
      spaceIndex3 = receivedData.indexOf(' ', spaceIndex3 + 1);
    }

    // // 打印解析结果
    // Serial.print("String: ");
    // Serial.println(strData);
    // Serial.print("Array Size: ");
    // Serial.println(arraySize);

    // // 打印整数数组的内容
    // Serial.println("Integer Array:");
    // for (int i = 0; i < 10; i++) {
    //   Serial.print(intArray[i]);
    //   Serial.print(" ");
    // }
    // Serial.println();

    if(strData.equals("fullAdder")){
      int a = intArray[0];
      int b = intArray[1];
      int sum[8], carry = 0;
            
      // // 示例：将读取到的数据通过串口进行回传
      // Serial.println("--------------begin-----------------");
      // Serial.println(a);
      // Serial.println(b);
      // Serial.println("-------------------------------");

      // 将两个数字转换为二进制数组
      fullAdder8(a, b, sum, &carry);

      for (int i = 0; i < 8; i++){
        Serial.println(sum[i]);
      }
      // Serial.println("-------------end------------------");
    }
    else if(strData.equals("halfAdder")){
      int a = intArray[0];
      int b = intArray[1];
      int sum, carry;

      // 示例：将读取到的数据通过串口进行回传
      // Serial.println("--------------begin-----------------");
      // Serial.println(a);
      // Serial.println(b);
      // Serial.println("-------------------------------");

      halfAdder(a, b, &sum, &carry);
      Serial.println(sum);
      Serial.println(carry);
            
            
      // Serial.println("-------------end------------------");
    }
    else if(strData.equals("majorityVoter")){ 
        int input1 = intArray[0]; // 将字符转换为整数
        int input2 = intArray[1]; // 将字符转换为整数
        int input3 = intArray[2]; // 将字符转换为整数

        // 示例：将读取到的数据通过串口进行回传
        // Serial.println("--------------begin-----------------");
        // Serial.println(input1);
        // Serial.println(input2);
        // Serial.println(input3);
        // Serial.println("-------------------------------");

        int output = majorityVoter(input1, input2, input3);
        Serial.println(output);
              
        // Serial.println("-------------end------------------");
    }
    else if(strData.equals("binaryComparator")){
      int input1 = intArray[0]; // 将字符转换为整数
      int input2 = intArray[1]; // 将字符转换为整数

      // 示例：将读取到的数据通过串口进行回传
      // Serial.println("--------------begin-----------------");
      // Serial.println(input1);
      // Serial.println(input2);
      // Serial.println("-------------------------------");

      int output[3];
      binaryComparator(input1, input2, output);
      for(int i = 0; i < 3; i++){
        Serial.println(output[i]);
      }
            
      // Serial.println("-------------end------------------");
    }
    else if(strData.equals("majorityVoter4bit")){   
      int input1 = intArray[0]; // 将字符转换为整数
      int input2 = intArray[1]; // 将字符转换为整数
      int input3 = intArray[2]; // 将字符转换为整数
      int input4 = intArray[3]; // 将字符转换为整数
      // 示例：将读取到的数据通过串口进行回传
      // Serial.println("--------------begin-----------------");
      // Serial.println(input1);
      // Serial.println(input2);
      // Serial.println(input3);
      // Serial.println(input4);
      // Serial.println("-------------------------------");

      int result = majorityVoter4bit(input1, input2, input3, input4);
      Serial.println(result);
            
      // Serial.println("-------------end------------------");
    }
    else if(strData.equals("encoder42")){
      int input1 = intArray[0]; // 将字符转换为整数
      int input2 = intArray[1]; // 将字符转换为整数
      int input3 = intArray[2]; // 将字符转换为整数
      int input4 = intArray[3]; // 将字符转换为整数
      int y1, y2;

      // 示例：将读取到的数据通过串口进行回传
      // Serial.println("--------------begin-----------------");
      // Serial.println(input1);
      // Serial.println(input2);
      // Serial.println(input3);
      // Serial.println(input4);
      // Serial.println("-------------------------------");

      encoder42(input1, input2, input3, input4, &y1, &y2);
      Serial.println(y1);
      Serial.println(y2);
            
      // Serial.println("-------------end------------------");
    }
    else if(strData.equals("decoder24")){
      int input1 = intArray[0]; // 将字符转换为整数
      int input2 = intArray[1]; // 将字符转换为整数
      int y1, y2, y3, y4;

      // 示例：将读取到的数据通过串口进行回传
      // Serial.println("--------------begin-----------------");
      // Serial.println(input1);
      // Serial.println(input2);
      // Serial.println("-------------------------------");

      decoder24(input1, input2, &y1, &y2, &y3, &y4);
      Serial.println(y1);
      Serial.println(y2);
      Serial.println(y3);
      Serial.println(y4);
            
      // Serial.println("-------------end------------------");
    }
    else if(strData.equals("multi4_1")){
      int input1 = intArray[0]; // 将字符转换为整数
      int input2 = intArray[1]; // 将字符转换为整数
      int input3 = intArray[2]; // 将字符转换为整数
      int input4 = intArray[3]; // 将字符转换为整数
      int input5 = intArray[4]; // 将字符转换为整数
      int input6 = intArray[5]; // 将字符转换为整数
      int y1;

      // 示例：将读取到的数据通过串口进行回传
      // Serial.println("--------------begin-----------------");
      // Serial.println(input1);
      // Serial.println(input2);
      // Serial.println(input3);
      // Serial.println(input4);
      // Serial.println(input5);
      // Serial.println(input6);
      // Serial.println("-------------------------------");

      multi4_1(input1, input2, input3, input4, input5, input6, &y1);
      Serial.println(y1);
            
      // Serial.println("-------------end------------------");
    } 
    else if(strData.equals("parity4")){
      int input1 = intArray[0]; // 将字符转换为整数
      int input2 = intArray[1]; // 将字符转换为整数
      int input3 = intArray[2]; // 将字符转换为整数
      int input4 = intArray[3]; // 将字符转换为整数
      int y1;

    // 示例：将读取到的数据通过串口进行回传
      // Serial.println("--------------begin-----------------");
      // Serial.println(input1);
      // Serial.println(input2);
      // Serial.println(input3);
      // Serial.println(input4);
      // Serial.println("-------------------------------");

      parity4(input1, input2, input3, input4, &y1);
      Serial.println(y1);

      // Serial.println("-------------end------------------");
    } 
  }
}
