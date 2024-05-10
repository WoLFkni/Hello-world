GHz: 10的负9次方<br>
> 中英词汇<br>

|英文/名词|中文/解释|
|:---:|:---:|
Rising or leading edge|上升沿
falling or trailing edge|下降沿
period |周期
Amplitude|A
Pulse width|tw
timing diagrams|时序图
DIP/ SOIC/ PLCC/ LCCC|芯片。引脚接出的方式不同
base/radix|基(***十***进制，***十六***进制)
logic(Voltage) level|逻辑电平(High/Low)
a bit|a signal number(0/1)
decimal number|十进制数
binary number|二进制数
Conversions|转换
1's Complement|反码(1-> 0;0->1)
2's Complement|补码(-7 in 4-bit digital system：1001)
sign bit|符号位
magnitude bits|符号位后面的那些位
Hexadecimal numbers|十六进制
octal numbers|八进制数
binary coded decimal|BCD
parity method|奇偶校验
even|偶数个1
odd|奇数个1
floating point number|浮点数
the inverter|反相器
the and gate|与门
SOP|与或形式（先乘后加）
POS|或与（先加后乘）
SOP Standard form(std.SOP)|每一项里所有变量都要出现的SOP
POS Standard form(std.POS)|每一项里所有变量都要出现的POS
minterms|最小项（所有变量（${A}$/$\overline{\text{A}}$）的乘积，若共有3个变量，则共有8个最小项）
maxterms|最大项（所有变量（${A}$/$\overline{\text{A}}$）的和，若共有3个变量，则共有8个最小项）
Karnaugh maps|卡诺图
don't care terms|无关项
AND-OR |与或(先与，后或)
AND-OR-Invert circuit|与或非(先与，后或，最后非)
Open Collector Gate|集电极开路门电路
Wired-AND|线与
Tri-state gate|三态门
Half-Adder | 半加器
Full-Adder|全加器
Parallel Adders|串形进位加法器，一个一个算，后面的等前面的算出来的$C_{out}$作为$C_{in}$
look-ahead adders|超前进位加法器，不用等前面的计算结果，每一位直接单独算，但是越到后面输入越多
carry generating signal|进位发生信号
carry propagating signal|进位传递信号
comparators | 比较器
decoders|解码器
seven segment display(7-seg)|红绿灯的那种数字表示方式
D.P(decimal Point)|小数点
LT(lamp test)|灯管检查
RBI|ripple blanking input
BI/RBO|blanking input/ripple blanking output
zero suppression|消零（ 小数点后，最后面的0，及，小数点前，最前面的0）
code converters|转换器
multiplexers(MUX)|复用器，数据选择器
latches|锁存器
bistable|双稳态
monostable |单稳态
astable |无稳态
edge-triggering|沿触发
flip-flop | 触发器
synchronous bistable devices|同步双稳态设备
bistable multivibrators|双稳态多纤颤器
positive edge (rising edge) | 上升沿
negative edge (falling edge)|下降沿
dynamic input indicator | 动态输入指示符（说明是ff，三角形，在clock处）
toggle mode|转换（0到1，1到0）
Asynchronous Preset and Clear Inputs|异步预置和清除输入
power dissipation | 能量耗散
speed-power product | 静态功耗*平均延迟
one-shot(monostable multivibrator) | 单稳态多谐振荡器
555 timer | 555定时器
Asynchronous Counters|异步计数器
cumulative delay|累积延迟
state transition diagram | 状态转移图（圆圈）
excitation|激励



> 一些记不得的东西……<br>

- place value system(weighted number system): 
    Decimal number system<br>
- Non-place value number system:
    Roman number system<br>
- 十进制小数转二进制小数：
    - 十进制小数点后面部分乘以2
    - 如果积整数部分=1，则对应的二进制数小数点后加一个1，如果积的整数部分=0，则对应的二进制小数点后加一个0
    - 先算出来的写前面(MSB)
- 补码
    - 法一：需要几位，就用2的几次方减去这个数的绝对值再转化为二进制
    - 法二：反码+1
    - 读数(负数)：
        - 法一：补码+1，再转化成十进制
        - 法二：直接读，最高位看作权重为原权重的相反数
- modified 2's complement
    - 正数：直接转化成二进制，在最前面加0
    - 负数：补码表示
- 有符号数加法
    - 超出原最大位数的最终进位舍弃
    - 加数中如果是负数则用补码表示
    - 最终最高位(已舍弃比最高位更大的最终进位)如果是1就是负数(按负数读)，如果是0就是正数。
    - 如果两个加数的符号相同，但是最终结果的符号不一致，则说明发生了overflow，此时结果不正确
- 有符号数减法
    - 减数写作补码(正负都写成补码)，被减数加减数的补码
- 二进制转十六进制
    - 四位四位转换，不够的在整个数的最前面添0，直至整个数的位数是4的倍数
- 二进制转八进制
    - 三位三位转
- 十进制转BCD
    - 十进制每一位独立转
- 格雷码
    - 二进制转格雷码
    ![Alt text](image.png)
    - 格雷码转二进制
    ![Alt text](image-1.png)
- floating point numbers
    - 32-bit single precision:
    ![Alt text](image-2.png)<br>
    转换：S表示符号，E先从二进制转换成十进制，然后减去127(`2^(n-1)`n为E的位数)，就是科学计数法中2的指数，F前面加上`1.`，就得到科学计数法表示的二进制值，此时再把对应的科学计数法数字部分的小数点对应往前移或往后移，得到正常二进制，然后转化成十进制就行。
    ![Alt text](image-3.png)
- 门
    - ![Alt text](image-4.png)
    - ![Alt text](image-5.png)<br>
    1 -> enable<br>
    0 -> inhibit
    - ![Alt text](image-6.png)
    - ![Alt text](image-7.png)
    - ![Alt text](image-8.png)
    - ![Alt text](image-9.png)<br>
    XOR
    - ![Alt text](image-10.png)<br>
    XNOR
    - ![Alt text](image-11.png)<br>
    集电极开路
    - ![Alt text](image-12.png)<br>
    线与<br>
    <!-- 只有集电极开路才能 -->
- POS form to Truth Table 
    - 使各乘数为零的变量取值组合 -> 0
    - 剩下的 -> 1
- universal Gates
    - 可以表示
        - Inverter
        - AND gate
        - OR gate
        - NOR gate
    - NAND gate
    - NOR gate
- 不用的引脚
    - CMOS
    ![Alt text](image-13.png)
    - TTL: 和CMOS一样或者**直接不管**
- 半加器
    - 2输入：加数 A，B
    - 2输出：进位 $\Sigma$，和的LSB(A,B相异或的结果) $C_{out}$
    ![Alt text](image-14.png)
- 全加器
    - 3输入：2个加数 A,B，1个低一位的进位 $C_{in}$
    - 2输出：进位 $\Sigma$，和的LSB(A,B相异或的结果) $C_{out}$
    ![Alt text](image-15.png)
- parallel Adders
    - 实现
    ![Alt text](image-16.png)
    - 符号
    ![Alt text](image-17.png)<br>
- look-ahead Adder
    - $g_i = A_i · B_i$
    - $p_i = A_i + B_i$
    - 进位：$c_{i+1} = A_iB_i+(A_i+B_i)c_i = g_i+p_ic_i$
    - 递推
    - decay仅为一个全加器的延迟
- Adders 
    - 74LS283
        - **delay** 17ns<br>
        - **features** look-ahead carry
    - Expanding: 两个4-bit adders 一个(一般右边)的$C_{out}$接到另一个(一般左边)的$C_{in}$，则变成一个8-bit的adder，同理可得16-bit(两个8-bit，即4个4-bit)
- Comparators
    - only for equality:
    ![Alt text](image-18.png)
    - 符号
    ![Alt text](image-19.png)
    - expand
        - 左边LSB,右边MSB
        - 左边的大小比较结果给右边，最左边A>B,A\<B都接地，A=B接HIGH，最右边先比自己的A和B,比完了比不出大小再看左边的输入。
        ![Alt text](image-20.png)
- Decoders
    - detect the presence of a specific input combination
    - Active HIGH / Active LOW:用于说明输出，即Active HIGH下，若输入为所需输入，则输出1；Active LOW下，若输入为所需输入，则输出0
    ![Alt text](image-21.png)
    - Bin/Dec：输入binary，输出decimal，4输入则16输出，一一对应
    ![Alt text](image-22.png)<br>
    上图为active low，故11输出为0，其余输出为1<br>
    ![Alt text](image-23.png)<br>
    上图有两个输入为active low的enable(select lines)，当这两个输入都为0时，才能实现他的功能
    - expand
        - ![expanding decoders](image-24.png)<br>
        只有一个decoder能进行选择，另一个所有输出都是1，A4是输入数据都最高位，对应权重是16，A4=1时，右边进行选择，可以看到，右边的decoder的输出都是在正常输出下加了16的，而A4=0时，左边工作，左边都是没有加16的
    - ***坑***：左边写的数字是权重，别搞错了，在1位置上的LSB,写函数的时候注意是F(MSB,...,LSB)
    - BCD/DEC 左边BCD 1 2 4 8，右边0～9
    - BCD/7-seg 左边BCD 1 2 4 8(上)+$\overline{\text{LT}}$ , $\overline{\text{RBI}}$(下)，右边 $\overline{\text{BI}}$/$\overline{\text{RBO}}$ a~g(1+7个输出)
        - $\overline{\text{LT}}$ active（0）的时候，所有输出均为1，连接的所有LED均亮
        - $\overline{\text{RBI}}$ （在小数点前的位数时）active（0）的时候，若BCD输入也为0，则输出全为0，所有LED均不亮。同时$\overline{\text{RBO}}$输出为active（0），***其余情况下，*** $\overline{\text{RBO}}$不会为active
        <!-- - $\overline{\text{BI}}$（在小数点后面的位数时）起与$\overline{\text{RBI}}$差不多的作用 -->
        - *小数点后面*：最右边$\overline{\text{RBI}}$接地，其余$\overline{\text{RBI}}$接右边decoder的$\overline{\text{RBO}}$
        - *小数点前面*：最左边$\overline{\text{RBI}}$接地，其余$\overline{\text{RBI}}$接左边decoder的$\overline{\text{RBO}}$
        ![Alt text](image-25.png)
        ![Alt text](image-26.png)
- encoder
    - 编码成二进制或BCD
    - DEC/BCD : 9输入，因为当所有输入都为0时，输入就是0，所以不需要单独的0输入，当输入为某个数时需要对应哪个输出为1，就把这个输入连到对应的输出的或门上。
    ![Alt text](image-27.png)
    - priority encoder 
        - if more than one input is active, the one with the highest order decimal digit will be active. 
        - ![Alt text](image-29.png)
        - 👆 8-line-to3-line encoder
        - $\overline{\text{EI}}$:enable input
        - $\overline{\text{EO}}$:empty output(指示芯片激活且没输入)
        - $\overline{\text{GS}}$:Group selection(指示芯片激活且有输入)
    - expansion: 右边EO接左边EI，如果是大于等于8的数，就会在A3(MSB)输出1，并且关闭左边的输入，同时原本的数减去8，使A0到A3输出相应的0/1
    ![Alt text](image-30.png)
- code converters
- multiplexer (data selectors)
    - 需要的最小项对应的十进制为HIGH
    - 位数超的话，就把最后超出的变量放进选择里，对应的数字是相应的没超的几个变量的最小项对应的十进制。
- latches
    - SET：Q=1
    - RESET：Q=0
    - 或非：active HIGH
    - 与非：active LOW
    - S-R latch 
        - 两个都active就输出什么都有可能
        - 两个都不active则保持原状，一般来说需满足至多只能有一个active
        - en active才能看S和R，否则不变
- flip-flops
    - D:同锁存器
    - J-K:
        - J active : set
        - K active : reset
        - 都active : 不变
        - 都不 active : 反转，HIGH变LOW, LOW变HIGH
    - Asynchronous Preset and Clear Inputs
        - 不由时钟控制直接set或reset
    - set-up time ： D的上一个变化的50%到时钟的50%之间的时间，超过这个时间才能有作用
    - Hold time ： 时钟50%到D再次变化的50%之间的时间，超过这个时间才是可靠的
- one-shots
    - nonretriggerable : 触发不叠加，一次触发的响应里混入另一次触发，则后一次触发无效
    - retriggerable : 触发叠加，触发延长
- 555 timer<br>
    - 充电时间`t1 = 0.7*(R1+R2)*C1`<br>
        $t_H = 0.7*(R_1+R_2)*C_1$<br>
    放电时间`t2 = 0.7*R2*C1`<br>
        $t_L = 0.7*R_2*C_1$<br>
    脉冲宽度`Tw = 1.1*R1*C1`<br>
        $t_w = 1.1*R*C$<br>
        $V(t) = V_{cc}*[1-e^{-\frac{t}{RC}}]$<br>
    周期`T = t1 + t2 = 0.7(R1+2*R2)C1`<br>
        $T = t_1 + t_2 = 0.7(R_1+2*R_2)C_1$<br>
    频率`f = 1/T = 1.44/((R1+2*R2)C1)`<br>
    $f = 1/T = \frac{1.44}{(R1+2*R2)C1}$<br>
    占空比`t1/T = (R1+R2)/(R1+2*R2)`<br>
    - 作one-shot
        - 响应时间$t_w = 1.1*R*C$<br>
    - 
> 问题： ch06 P25,P49 GS<br>
ch07-3 P5 T flip-flops