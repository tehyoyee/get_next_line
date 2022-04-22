# Get_next_line

This project is about programming a function that returns a line
read from a file descriptor.

<br>

|**함수 이름**|get_next_line|
|:--|:--|
|**프로토타입**|`char *get_next_line(int fd);`|
|**제출할 파일**| get_next_line.c, get_next_line_utils.c, get_next_line.h|
|**매개변수**|읽어들일 파일의 디스크립터 (서술자)|
|**반환값**|읽혀진 라인 : 한 줄이 제대로 읽힘 <br> NULL : 읽을 라인이 더이상 없거나 에러 발생|
|**사용가능한 <br>외부 함수** |`read, malloc, free`|
|**설명**|파일 디스크립터로부터 한 줄을 읽고, <br>반환하는 함수를 작성하시오.|

<br>

> `-D BUFFER_SIZE=xx`플래그를 사용하여 컴파일 진행.

> BUFFER_SIZE만큼만 문자열 읽으며 정적변수에 저장. <br>
new line이 읽히면 정적변수에 있던 문자열을 슬라이싱하여 1줄 반환. <br>
남은 문자열은 저장하여 함수가 다시 실행되면 새로 읽힌 문자열과 연결.

> Anyway, 함수 1회 실행시 1줄 반환.