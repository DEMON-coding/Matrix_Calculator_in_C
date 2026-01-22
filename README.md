# A Matrix Calculator - 矩阵运算系统
C语言实现的交互式矩阵运算系统，支持17种矩阵操作，包含完整的内存管理和健壮性设计。

## 📋 项目简介

这是一个基于C语言的综合程序设计项目，实现了完整的矩阵运算功能。**所有代码包含在单个`main.c`文件中**，采用模块化函数设计，便于理解和修改。

### 核心功能
- **矩阵基本运算**：加、减、乘（支持手动输入和随机生成）
- **矩阵性质计算**：转置、求逆（高斯-约当消元法）、子矩阵提取
- **统计分析**：元素均值、最大值、最大值归一化
- **智能健壮性**：维度校验、可逆性检测、内存安全检查
- **交互体验**：实时菜单、清屏功能、错误回退

## 🛠️ 技术栈

- **语言**：C (C99标准)
- **开发环境**：Visual Studio（使用`scanf_s`安全输入）
- **平台**：Windows（含`system("pause")`等系统命令）
- **算法**：高斯-约当消元法（矩阵求逆）

## 📦 项目结构
本项目采用**单文件实现**，结构简洁：
```
Matrix_Calculator_in_C/
├── Matrix_Calculator_in_C/
│   ├── Matrix_Calculator_in_C.cpp             # 主程序
│   ├── Matrix_Calculator_in_C.vcxproj         # VS项目文件
│   └── Matrix_Calculator_in_C.vcxproj.filters
├── .gitattributes                             # Git属性配置
├── .gitignore                                 # 忽略编译产物
├── LICENSE.txt                                # 许可证文件
├── Matrix_Calculator_in_C.sln                 # VS解决方案文件
└── README.md                                  # 项目说明文档
```
 **⚠️ 注意**  ：所有函数均在`Matrix_Calculator_in_C.cpp`中实现，未分离头文件，适合快速部署。

## 🔧 快速开始
### 方法一：Visual Studio（**最推荐**）
1. **克隆仓库**到本地：
   ```bash
   git clone https://github.com/DEMON-coding/Matrix_Calculator_in_C.git 
   ```
2. **进入项目根目录**，**双击`Matrix_Calculator_in_C.sln`**
3. Visual Studio启动后，直接按`Ctrl+F5`编译运行
4. **无需任何配置**，即可开始矩阵运算！

### 方法二：命令行编译（Windows）
```bash
# 1. 打开Visual Studio开发者命令提示符
# 2. 切换到项目根目录

# 编译命令（注意指定子目录中的源文件）
cl Matrix_Calculator_in_C\Matrix_Calculator_in_C.cpp /Fe:matrix_calc.exe

# 运行
matrix_calc.exe
```

### 方法三：GCC编译（跨平台，需修改代码）
**移植步骤**：
1. 将`Matrix_Calculator_in_C.cpp`重命名为`main.c`
2. **修改代码**：
   - 将所有`scanf_s`替换为`scanf`
   - 删除或注释掉`system("pause")`和`system("cls")`
3. **编译**：
   ```bash
   gcc Matrix_Calculator_in_C/main.c -o matrix_calc -lm
   ./matrix_calc
   ```

## 🚀 使用指南

程序启动后显示交互式菜单，输入数字选择功能：

```
***************************************************
1: 输入矩阵，求均值
2: 生成随机矩阵，求均值
3: 输入两个矩阵，求和
4: 输入两个矩阵，求差
5: 输入两个矩阵，求积
6: 生成两个随机矩阵，求和
...
16: 输入方阵，求逆矩阵
17: 生成随机方阵，求逆矩阵
0: 结束!
***************************************************
```

**特色交互**：
- 输入`-1`：随时呼出菜单
- 输入`0`：退出并清屏
- 输入错误：自动提示并允许重试

### 操作示例

**示例1：求矩阵转置**
```
请输入数字以使用对应功能：12
请输入矩阵行数：3
请输入矩阵列数：2
请输入矩阵：
1 2
3 4
5 6
矩阵的转置为：
1.000000 3.000000 5.000000
2.000000 4.000000 6.000000
输出完毕！
您可以继续使用或退出，输入-1呼出菜单：
```

**示例2：矩阵求逆验证**
```
请输入数字以使用对应功能：17
请输入方阵阶数：3
随机生成矩阵成功！
产生的矩阵为：
49.827570 47.080905 6.103702
18.552202 12.033448 15.947447
45.645009 23.720511 38.555559
矩阵的逆为：
0.020413 -0.397999 0.161390
0.003009 0.391346 -0.162346
-0.026018 0.230414 -0.065249
输出完毕！
```

**示例3：错误处理演示**
```
请输入数字以使用对应功能：16
请输入方阵阶数：3
请输入矩阵：
0 0 0
0 0 0
0 0 0
矩阵不可逆！
```

## 🎯 代码设计特点

### 1. 数据结构定义
```c
typedef struct {
    double** mat;  // 动态二维数组指针
    int row;       // 行数
    int col;       // 列数
} Matrix;
```

### 2. 核心函数原型（与实际代码一致）
```c
// 初始化与内存管理
void InitialMatrix(Matrix* T, int row, int col);
void DestroyMatrix(Matrix* T);

// 矩阵运算（实际传入row/col参数）
int AddMatrix(Matrix* A, Matrix* B, Matrix* C, int row, int col);
int MinusMatrix(Matrix* A, Matrix* B, Matrix* C, int row, int col);
int MultiMatrix(Matrix* A, Matrix* B, Matrix* C);

// 高级功能
int ReverseMatrix(Matrix* A, Matrix* B, int row, int col); // 高斯-约当消元
double MaxMatrix(Matrix* T, int row, int col);
void PrintMatrix(Matrix* T, int row, int col);
```

### 3. 健壮性设计
- **内存安全**：双重检查`malloc`返回值，提供`DestroyMatrix`统一释放
- **维度校验**：所有操作前检查`row>0 && col>0`
- **可逆性检测**：通过行阶梯变换检测秩与阶数关系
- **零矩阵处理**：归一化前检测并提示
- **边界检查**：子矩阵提取时严格验证索引范围

### 4. 独特实现
- **减法优化**：`MinusMatrix`通过取反B矩阵后调用`AddMatrix`实现
- **交互增强**：输入`-1`可随时呼出菜单，`system("cls")`清屏防刷屏
- **随机种子**：`srand((unsigned)time(NULL))`确保每次运行结果不同

## ✅ 测试覆盖

代码已验证的场景：
- 正常矩阵运算（加、减、乘、转置）
- 边界值（零矩阵、单位矩阵、1×1矩阵）
- 错误输入（负数维度、不可逆矩阵、越界索引）
- 数值稳定性（随机50以内浮点数）
- 逆矩阵验证：`A × A⁻¹ ≈ I`（单位矩阵）

## 📊 性能分析

| 操作类型 | 时间复杂度 | 空间复杂度 | 备注 |
|--------|--------|--------|--------|
| 加减法 | O(n²) | O(n²) | 逐元素操作 |
| 乘法 | O(n³) | O(n²) | 三重循环实现 |
| 求逆 | O(n³) | O(n²) | 高斯-约当消元法 |
| 转置/归一化 | O(n²) | O(1)额外 | 原地操作 |

**测试数据**：随机50以内浮点数，支持最大维度受内存限制

## ⚠️ 注意事项

1. **Windows专属**：`system("pause")`和`system("cls")`在Linux下需替换
2. **安全输入**：`scanf_s`为VS特有，GCC用户请改用`scanf`并增加缓冲区大小参数
3. **内存泄漏**：程序正常退出时会释放所有内存，异常退出需检查
4. **矩阵大小**：建议单次操作不超过1000×1000维，避免栈溢出
