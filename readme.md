# cpp00

## ex00


## ex01


## ex02
< 접근법 >
- 로그를 보고, 어떤 부분에서 어떠한 메소드가 쓰였는지 파악
- 로그 : result.log

```
[19920104_091532] index:0;amount:42;created (생성자)
......				...		...		...
[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0 ()
[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0 ()
......				...		...		...			...
[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1 ()
......				...		...		...			...			...

[19920104_091532] index:0;amount:47;closed (소멸자)
```