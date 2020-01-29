# Jardim Automatico
=============================================================

Sistema Automático para Jardim / Automatic Gardening System

### Requisitos mínimos ###
- Entender o funcionamento dos componentes do Arduino
- Saber programar na linguagem C++ caso decida customizar este projeto
- Lembrar que podem haver variações de versões do componentes, e isso pode causar alguma instabilidade ou até o não funcionamento do código e do esquema aqui apresentado.

# Sobre #
Este sistema utiliza componentes compatíveis com Arduino, porém utilizando o NodeMCU como controladora. Os sensores de humidade e temperatura nem sempre são precisos: é importante lembrar também que dependendo de como ficar a instalação, a temperatura pode influenciar nos conectores e causar mal contato caso não estejam encaixados de forma apropriada.
Outra nota importante: este é um projeto que não deve ser utilizado profissionalmente. A iniciativa é apenas de configurar o básico, porém a instabilidade do sistema todo pode ocorrer devido a fatores externos: calor, falta de energia, peças com mal contato, etc


# Logica #

O sistema basicamente verifica algumas regras para acionar a bomba dagua:
- Se o tanque de agua estiver cheio, ele vai esvaziar até atingir a marca mínima;
- Se o solo estiver muito seco (no caso estou utilizando so 1 sensor para fins didaticos, é possivel colocar mais)
- Se o horário programado for atingido
- Em todos os casos, se houver falta de agua, o sistema não aciona a bomba dagua;

# Componentes #

```NodeMCU Lolin 0.9```: Controlador de todos componentes

```DHT22```: Calcula a temperatura e humidade

```Humidity Sensor```: Calcula a humidade do solo

```Pump```: Bomba de agua 12v

```Relay```: Relê que liga ou desliga a bomba de agua

# Esquema #

![Conexões](https://github.com/gilnei/jardimautomatico/blob/master/Jardim_bb.png)

# Blynk #

Mais informações sobre o Blynk (como instalar etc)
https://docs.blynk.cc/
https://github.com/blynkkk/blynk-server/blob/master/README.md


Blynk basicamente é um serviço que permite com que você mapeie seus componentes e controle remotamente pelo aplicativo. Eu utilizo Blynk juntamente com o HomeBridge, pois utilizo a plataforma da Apple, que se comunica com estes componentes pelo HomeBridge. Tenho algumas dicas de instalação do Homebridge em outro post meu aqui: xXXXXXX
Eu utilizo o Blynk localmente, pois não quero pagar por créditos on-line, sendo que esse projeto é só um protótipo, mas você pode utilizar o servidor online para criar a interface e operar pelo próprio aplicativo do Blynk.

# Antes de rodar o código #

Lembre-se de alterar o arquivo ```credenciais.h``` com algumas informações:

char auth[] = "XXXXXXXXXXXXX";   --> esta é a chave do Blynk para que você consiga conectar os componentes no painel do aplicativo     
char ssid[] =  "SSID OU NOME DA SUA REDE";       --> coloque o nome da sua rede, preferencialmente 2.4G por conta de outros componentes
char pass[] =  "SENHA DA SUA REDE";        --> a senha da sua rede
char server[]=  " IP DO BLYNK ";       --> coloque o IP do seu servidor Blynk ou entao o endereço on-line: 

# 
