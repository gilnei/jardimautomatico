# Jardim Automatico
=============================================================

Sistema Automático para Jardim / Automatic Gardening System

### Requisitos mínimos ###
- Entender o funcionamento dos componentes do Arduino
- Saber programar na linguagem C++ caso decida customizar este projeto
- Lembrar que podem haver variações de versões do componentes, e isso pode causar alguma instabilidade ou até o não funcionamento do código e do esquema aqui apresentado.

### Sobre ###
Este sistema utiliza componentes compatíveis com Arduino, porém utilizando o NodeMCU como controladora. Os sensores de humidade e temperatura nem sempre são precisos: é importante lembrar também que dependendo de como ficar a instalação, a temperatura pode influenciar nos conectores e causar mal contato caso não estejam encaixados de forma apropriada.
Outra nota importante: este é um projeto que não deve ser utilizado profissionalmente. A iniciativa é apenas de configurar o básico, porém a instabilidade do sistema todo pode ocorrer devido a fatores externos (calor, falta de energia, peças com mal contato, etc)


```NodeMCU Lolin 0.9```: Controlador de todos componentes

```DHT22```: Calcula a temperatura e humidade

```Humidity Sensor```: Calcula a humidade do solo

```Pump```: Bomba de agua 12v

```Relay```: Relê que liga ou desliga a bomba de agua

### Esquema ###

![Conexões](https://github.com/gilnei/jardimautomatico/blob/master/Jardim_bb.png)
