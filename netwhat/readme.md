- **NETWHAT**

- What is IP?

  - IP(Internet Protocol)란 네트워킹이 가능한 장비를 식별하기 위해 부여된 고유 주소이다.
  - IPv4
    - IP version 4의 약자로 전 세계적으로 사용된 첫 번째 인터넷 프로토콜이다.
    - 주소는 32bit 방식으로, 8bit씩 4자리로 되어있다.
  - IPv6
    - IPv4의 주소체계를 128bit 크기로 확장한 인터넷 프로토콜 주소이다.
    - 주소는 128bit 방식으로, 16bit씩 8자리로 구분한다.

- IP address Class

  - Class는 하나의 IP주소에서 네트워크 영역과 호스트 영역을 나누는 방법이자 약속이다.

  - 네트워크 크기에 따른 구분으로 IP주소를 3개의 class로 나눈다.

  - 하나의 네트워크에서 몇 개의 호스트 IP를 가질 수 있는지에 따라 class를 나눈다.

    ![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/b7f2abba-00d6-4f2c-a089-bae7cb65d27e/Untitled.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/b7f2abba-00d6-4f2c-a089-bae7cb65d27e/Untitled.png)

  - class A

    - 네트워크가 가질 수 있는 호스트의 수가 가장 많다.
    - IP주소를 32자리 2진수로 표현했을 때, 맨 앞자리의 수가 항상 0인 경우.
    - 0xxx xxxx. xxxx xxxx. xxxx xxxx. xxxx xxxx 와 같이 되어있다.
    - IP 주소 : 0.0.0.0 ~ 127.255.255.255
    - 네트워크 주소의 범위 : 0~127, 128개 중에 0.x.x.x와 127.x.x.x(자기 ip)를 제외하고 1.0.0.0 ~ 126.0.0.0 범위의 총 126개.
    - 호스트 주소의 범위 : 2^24 - 2
      - -2 인 이유
        - 모두가 1인 경우 브로드캐스트 주소로 사용.
        - 모두가 0인 경우 네트워크 주소로 사용.

  - class B

    - IP주소를 32자리 2진수로 표현했을 때, 맨 앞자리의 수는 항상 10인 경우.
    - 10xx xxxx. xxxx xxxx. xxxx xxxx. xxxx xxxx 와 같이 되어 있다.
    - IP 주소 : 128.0.0.0 ~ 191.255.255.255
    - 네트워크 주소의 범위 : 10xx xxxx. xxxx xxxx 에서 x들이 가질 수 있는 경우의 수, 2^14 개
    - 호스트 주소의 범위 : xxxx xxxx. xxxx xxxx 에서 x들의 경우의 수인 (2^16) - 2
      - -2 인 이유
        - 모두가 1인 경우 브로드캐스트 주소로 사용.
        - 모두가 0인 경우 네트워크 주소로 사용.

  - class C

    - IP주소를 32자리 2진수로 표현했을 때, 맨 앞자리의 수는 항상 110인 경우.
    - 110x xxxx. xxxx xxxx. xxxx xxxx. xxxx xxxx 와 같이 되어 있다.
    - IP 주소 : 192.0.0.0 ~ 233.255.255.255
    - 네트워크 주소의 범위 : 110x xxxx. xxxx xxxx. xxxx xxxx  에서 x들이 가질 수 있는 경우의 수, 2^21 개
    - 호스트 주소의 범위 : xxxx xxxx 에서 x들의 경우의 수인 (2^8) - 2
      - -2 인 이유
        - 모두가 1인 경우 브로드캐스트 주소로 사용.
        - 모두가 0인 경우 네트워크 주소로 사용.

  - 공인 IP와 사설 IP

    - 공인 IP
      - 인터넷 사용자의 로컬 네트워크를 식별하기 위해 ISP(인터넷 서비스 공급자)가 제공하는 IP 주소.
      - 공용 IP주소라고도 하며 외부에 공개되어 있는 IP 주소.
      - 공인 IP는 전세계에서 유일한 IP 주소를 갖는다.
    - 사설 IP
      - 일반 가정이나 회사 내에 할당된 네트워크의 IP주소.
      - 로컬 IP, 가상 IP라고도 한다.
      - IPv4의 주소부족으로 인해 서브넷팅된 IP이기 때문에 라우터에 의해 로컬 네트워크상의 PC나 장치에 할당된다.

    ![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/db938a86-6e22-4a6e-9cac-6a656d3d4c9e/Untitled.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/db938a86-6e22-4a6e-9cac-6a656d3d4c9e/Untitled.png)

  - Loopback or Localhost

    - IPv4 및 IPv6에서, **자기 자신을 가리키기 위한 목적으로 쓰기 위해** 예약된 IP 주소이다.
    - IPv4의 경우 127.0.0.0부터 127.255.255.255(127.0.0.0/8) 까지 있으며, 보통 127.0.0.1을 사용한다.
    - IPv6의 경우 넓은 대역을 할당하기에는 아까웠는지 IPv6은 ::1/128, 딱 한 개의 주소만 사용한다.

  - Netmask

    - 네트워크 주소 부분의 비트를 1로 치환한 것.
    - IP주소와 netmask를 AND연산 하면 네트워크 주소를 얻을 수 있다.

    ![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/4e902ea3-cf3b-4b33-8468-7ed36d154886/Untitled.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/4e902ea3-cf3b-4b33-8468-7ed36d154886/Untitled.png)

  - Subnet/Subnet mask

    - IP주소와 같이 32bit의 2진수의 형태.
    - 한 개의 네트워크를 여러개의 subnet으로 분할 하는 것.
    - 서브넷화 하는 경우에는 네트워크 주소 부분의 비트를 연장하고 나머지 호스트 부분이 호스트 식별자가 된다.

    ![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/1df28aea-c2ab-4c56-b9c8-2f1ae1674704/Untitled.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/1df28aea-c2ab-4c56-b9c8-2f1ae1674704/Untitled.png)

  - Subnetting

    - 한 개의 subnet mask를 이용해 여러 개의 subnet으로 분할하는 것.

  ![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/2d2bab53-c2e1-44b3-ad2d-cae42a525ee6/Untitled.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/2d2bab53-c2e1-44b3-ad2d-cae42a525ee6/Untitled.png)

  - Network/Broadcast address
    - Network address
      - 하나의 네트워크를 가르키기 위한 주소이다.
      - 해당 네트워크의 첫번째 IP address.
      - IP address 와 subnet mask의 AND연산을 통해 얻을 수 있다.
    - Broadcast address
      - 특정 네트워크에 속하는 모든 호스트가 가지게 되는 주소.
      - 네트워크에 있는 클라이언트 모두에게 보내기 위해 사용.
      - 해당 네트워크에 속하는 모든 IP주소 가운데 맨 마지막 IP address.
      - subnet mask의 '0'을 모두 '1'로 바꾸면 계산할 수 있다.
    - ex)
      - C class
        - IP address : 192.168.16.1/24
        - Subnet mask : 255.255.255.0
        - network address : 192.168.16.0
        - broadcast address : 192.168.16.255