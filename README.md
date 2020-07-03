# beakjoon

백준 문제들에 대한 코드를 담은 repository입니다.<br>

## 2798번 블랙잭

브루트 포스라는 카테고리의 문제인데<br>
그냥 쉽게 말해서 무식하게 전체 탐색하면 된다고 한다.<br>
브루트 포스 뜻을 검색하기 전에는 전체를 탐색하기위한<br>
효율적인 알고리즘중 하나를 뜻하는 줄 알았다.<br><br>

그래서 검색하기전에 일단 생각나는대로 만들어 보자고 한게 [`commit`](https://github.com/soulsystem00/beakjoon/commit/05ad34816832a107402ea5e5d57c57f2729902b7) 이다.<br>

그냥 for문을 이용하여 3개의 값을 가져와 저장하도록 만들어주었다.

아마 빅오표기법으로는 for문을 3번 썼으니 n^3이 아닐까 생각한다.

그래서 당연히 시간초과가 될 줄 알았고 역시나 시간초과가 나왔다.

그리고 나서 브루트 포스에 대해 검색을 해보니 나의 코드와 별반 다를바가 없어서

약간의 수정을 해주었다.

중복제거 과정을 합치면 N^4가 되지만 중복제거과정을 빼서 N^3을 만들어주니 시간초과가 일어나지 않고

제대로 채점이 되었다.

당연히 시간초과가 나고 다른 방법을 찾아야 할 줄 았았는데 정답처리가 되어서 상당히 깜짝 놀랐었다.

## 2231번 분해합

브루트 포수 카테고리의 문제이다.<br>
>어떤 자연수 N이 있을 때, 그 자연수 N의 분해합은 N과 N을 이루는 각 자리수의 합을 의미한다.<br> 어떤 자연수 M의 분해합이 N인 경우, M을 N의 생성자라 한다.<br> 예를 들어, 245의 분해합은 256(=245+2+4+5)이 된다.<br> 따라서 245는 256의 생성자가 된다. 물론, 어떤 자연수의 경우에는 생성자가 없을 수도 있다.<br> 반대로, 생성자가 여러 개인 자연수도 있을 수 있다.<br>자연수 N이 주어졌을 때, N의 가장 작은 생성자를 구해내는 프로그램을 작성하시오.

일단 분해합을 구하는 프로그램부터 만들어보았다.<br>


입력으로 주어지는 자연수의 범위가 1부터 100000까지 이기 때문에<br> 
if문을 여러번 사용하여 각 자리를 저장하고 더해주는 방법으로 분해합을 구할수도 있었느나<br>
그 방법은 너무나 귀찮기 때문에<br>
첫번째 방법으로는 <br>
string 형으로 입력을 받아서 각 자리를 인덱스로 접근하여 더해주는 방식으로 구해보았다.<br>
<I>주석부분 참고</I><br><br>

두번째 방법으로는 반복문을 이용해 주었다.<br>
먼저 int형으로 입력받은 숫자의 자릿수를 구해주었다.<br>
그리고 나서 입력받은 숫자를 10의 n승만큼 나누어 주는 것을 자릿수만큼 반복을 해주었다.<br>
이때 n은 최대 자리수 부터 하나씩 감소시키도록 만들어 주었다.<br><br>

그렇게 되면 배열에는 다음과 같이 저장이 된다.
~~~C
a[0] = 1 
a[1] = 12 
a[2] = 123 
a[4] = 1234
~~~
이렇게 저장된 각 값들을 끝에 부터 현재 인덱스 - 이전 인덱스 * 10 을 해주면<br>
각 자리수의 숫자들을 구할 수 있게 된다.<br>
~~~C
a[0] = 1 
a[1] = 2 
a[2] = 3 
a[4] = 4
~~~
이렇게 구해진 값들을 바탕으로 분해합을 구할수 있었다.<br><br>

이렇게 만든 분해합 구하는 방법을 1부터 입력받은 숫자까지 대입해주는 식으로 반복시켜주었다.<br>
반복을 하다가 중간에 입력받은 값과 분해합이 같으면<br>
현재 계산하고 있던 값을 출력해주고 종료하는 식으로 만들어 주었다.<br><br>

솔직히 엄청 비효율적이긴 해서 당연히 시간초과가 날줄 알았다.<br>
근데 시간초과가 나지 않아서 놀랐다.<br><br>

다른사람의 코드를 살펴보니<br>
if문을 사용하여 각 자리의 수를 구해주었더라<br>
그런식으로 코드를 작성하니 속도는 훨씬 빠른것으로 나와있었다.<br>
다만 단점은 자연수가 주어진 범위를 넘어섰을때는 오류가 날 것이다.<br>

## 7568번 덩치

사람의 수와 몸무게, 키를 입력받아<br>
덩치 등수를 구하면 된다.<br>
이때 덩치 등수는 자신보다 몸무게와 키가 큰 사람의 수를 말한다.<br><br>

먼저 사람 구조체를 정의를 해주었다.
~~~C++
typedef struct _Person
{
	int weight;
	int height;
}Person;
~~~
이제 이 구조체를 이용해서 배열을 만들면 더 편리하게 사람의 몸무게와 키를 관리할 수 있다.<br><br>

전체적인 알고리즘은 다음과 같다.<br>
>1. 사람의 수를 입력받아 그만큼 동적할당을 해준다.
>2. 사람의 몸무게와 키를 입력받아 배열에 저장한다.
>3. 한 사람의 키와 몸무게를 다른 모든 사람들과 비교를 한다.
>4. 덩치 조건에 만족하면 rank의 값을 1 증가 시켜준다.

다른 사람들의 코드를 보니 나와 비슷하게 코드를 짠거 같았다.<br>
그래서 시간도 대부분 비슷하게 나왔다.<br><br>

그런데 몇몇 사람은 조금 더 빠르게 시간이 측정된 사람도 있었는데<br>
이 경우에는 동적할당을 쓰지 않고 정적배열을 만들어 비교를 해주었다.<br>
이런경우는 입력의 범위가 정해져 있었기 때문에 가능한거 같았다.<br>

