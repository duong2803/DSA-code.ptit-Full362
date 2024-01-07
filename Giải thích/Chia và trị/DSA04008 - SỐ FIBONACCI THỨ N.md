# Intuition
<!-- First thoughts on how to solve this problem -->
Với điều kiện $N <= 10^9$ thì việc for trâu đến $N$ để tính Fibo là khá lâu, nên việc này coi như bỏ.

Cách làm bài này là sử dụng lũy thừa ma trận, mọi người có thể search google kiểu **"Calculate nth fibonacci using matrix exponentiation"** để tìm hiểu. Ở đây mình sẽ trình bày lại cách làm theo nhân ma trận cho ai chưa hiểu, đồng thời giải quyết theo một khác (sử dụng công thức).
# Approach
<!-- Approach to solve the problem -->
## Cách 1: Nhân ma trận
Ý tưởng là sử dụng ma trận để lưu các giá trị cần thiết cho việc tính toán và tìm cách **chuyển trạng thái** tới ma trận khác bằng việc nhân ma trận. Cụ thể trong bài này, để tính số Fibonacci thứ $i$ thì cần phải biết giá trị của 2 số Fibonacci trước đó. Mục tiêu của chúng ta là biến đổi: 

$$
\begin {bmatrix} 
F_{i - 1} \\
F_{i - 2} \\
\end{bmatrix}
\rightarrow  \begin {bmatrix}
F_{i} \\
F_{i - 1} \\
\end{bmatrix}
$$

Gọi $F_i$ là số Fibonacci thứ i, khi đó ta cần tính ma trận $?$ sao cho: 

$$
\begin {bmatrix} 
F_i \\
F_{i - 1} \\
\end{bmatrix}
= ? * \begin {bmatrix}
F_{i - 1} \\
F_{i - 2} \\
\end{bmatrix}
$$  

Có thể dễ dàng tìm được ma trận $?$ nếu viết phương trình trên dưới dạng hệ phương trình. Ta có:

$$
\left\{\begin{matrix}
F_i = 1 * F_{i - 1} + 1 * F_{i - 2}\\ 
F_{i - 1} = 1 * F_{i - 1} + 0 * F_{i - 2}\\
\end{matrix}\right.
$$

Như vậy ma trận $?$ là: 

$$
\begin {bmatrix} 
1 & 1 \\
1 & 0 \\
\end{bmatrix}
$$

Hay ta có:

$$
\begin {bmatrix} 
F_i \\
F_{i - 1} \\
\end{bmatrix}
= \begin {bmatrix} 
1 & 1 \\
1 & 0 \\
\end{bmatrix} * \begin {bmatrix}
F_{i - 1} \\
F_{i - 2} \\
\end{bmatrix}
$$  

Từ đó, chúng ta có thể dễ dàng tính số Fibonacci thứ n theo cách sau:

$$
\begin {bmatrix} 
F_n \\
F_{n - 1} \\
\end{bmatrix}
= \begin {bmatrix} 
1 & 1 \\
1 & 0 \\
\end{bmatrix} 
* 
\begin {bmatrix} 
1 & 1 \\
1 & 0 \\
\end{bmatrix}
* 
\begin {bmatrix} 
1 & 1 \\
1 & 0 \\
\end{bmatrix}
* 
\cdots
*\begin {bmatrix}
F_{1} \\
F_{0} \\
\end{bmatrix} 
= \begin {bmatrix} 
1 & 1 \\
1 & 0 \\
\end{bmatrix}^{n - 1} 
*
\begin {bmatrix}
F_{1} \\
F_{0} \\
\end{bmatrix} 
$$

Độ phức tạp của việc tính lũy thừa của ma trận có thể được giảm xuống $O(2^3*log(n))$ bằng việc sử dụng lũy thừa nhị phân (giống việc tính lũy thừa của 1 số).

## Cách 2: Dùng công thức

Khai triển "trâu" công thức của Fibonacci ta có:

$F_i = F_{i - 1} + F_{i - 2}$

$= F_2 * F_{i - 1} + F_1 * F_{i - 2}$  
do $(F_1 = F_2 = 1)$

$\Leftrightarrow F_i = F_2 * F_{i - 2} + F_2 * F_{i - 3} + F_1 * F_{i - 2}$

$= F_{i - 2} * (F_1 + F_2) + F_2 * F_{i - 3}$ 

$=F_3 * F_{i - 2} + F_2 * F_{i - 3}$

(Để ý quy luật)

$\Leftrightarrow F_i =F_4 * F_{i - 3} + F_3 * F_{i - 4}$

$\Leftrightarrow F_i =F_5 * F_{i - 4} + F_4 * F_{i - 5}$

$\Leftrightarrow F_i =F_6 * F_{i - 5} + F_5 * F_{i - 6}$

$\cdots$

Nội suy được ra công thức sau (có thể thử lại với những F nhỏ để kiểm chứng):

$F_i = F_{i / 2 - 1} * F_{i / 2} + F_{i / 2 + 1} * F_{i / 2 + 2}$

Từ đó dễ dàng có thể sử dụng đệ quy có nhớ để tính toán giá trị của $F_i$

# Complexity
- Time complexity: $O(log(n))$
- Space complexity: $O(log(n))$

# Code
Dưới đây là code của cách 2 (Cách 1 anh em tự làm :v)
```c++
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

unordered_map<ll, ll> f;

ll fib(ll n){
	if(f.find(n) != f.end())
		return f[n] % mod;
	if(n == 1 || n == 2) return 1;
	return f[n] = (fib((n - 1) / 2) * fib(n / 2) % mod + fib((n + 1) / 2) * fib((n + 2) / 2) % mod) % mod; 	
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		ll n; 
		cin >> n;
		cout << fib(n) << '\n';
	}
	return 0;
}
```