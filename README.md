# Tempearture Gateway application

## Overview
Temperature gateway application runs on Ci40 which acts as a gateway For MikroE board.MikroE board acts as a client which holds temperature resource. it continously observes the constrained device And upon recieving the data,it timestamps the information including  Constrained deviceID,temperature data,measurement unit And sends it to FlowCloud Datastore. Simultaneously it also publishes to device topic(measurement_changed) about This information, which gets notified by user.Gateway allows only one week's worth of data to be stored in datastore, And it purges the data that is older than one week.During operation gateway checks once per hour For data that has past the seven day rule.
On bootup it checks the device settings And looks For a datastore name to use And delta value to provide the constrained application with. By Default it takes them as templogger And one respectively And adds them to device settings If they are Not  specified.
It also waits For notication from subscribed device topic (device_setting_changed) about the change in device settings.If it gets notified , then it uses the New specified datastore And delta value. 


Gateway application serves two purposes:
- It acts as Awalwm2m server to communicate with Awalwm2m client that is running on a constrained device.
- It acts as Awalwm2m client to communicate with Awalwm2m server on FlowM2M

| Object Name               | Object ID      | Resource Name | Resource ID |
| :----                     | :--------------| :-------------| :-----------|
| "TemperatureSensorDevice" | 3200           | "Counter"      | 5501        |
| "TemperatureSensorDevice" | 3311           | "On/Off"       | 5850        |


## Prerequisites
Prior to running button gateway application, make sure that:
- Awalwm2m client daemon(awa_clientd) is running.
- Awalwm2m server daemon(awa_serverd) is running.
- Awalwm2m bootstrap daemon(awa_bootstrapd) is running.
- Gateway Device provisioning is done.
- Constrained Device provisioning is done.
**NOTE:** Please do "ps" on console to see "specific" process is running or not.

## Running Application on Ci40 board
Temperature gateway Application is getting started as a daemon. Although we could also start it from the command line as :

$ temperature_gateway_appd

Output looks something similar to this :

Temperature Gateway Application

------------------------


client session established


server session established


Wait until Gateway device is provisioned


Gateway is provisioned.


Wait until Constarained device is provisioned


Constrained device is provisioned


Device registered successfully


Defining flow objects on server

Defining flow objects on client

Waiting for constrained device 'TemperatureSensorDevice' to be up

Constrained device TemperatureSensorDevice registered


The dataStoreName is : null

Adding a new device setting gateway_measurements_datastore...


Delta value is : null

Delta value written to /3300/0/5900 

Adding a new device setting delta_resource...


Subscribe Successful


#<Measurement>
#<deviceId type="String">2D 97 3F 30 1C A0 A0 40 86 FD 0E 3B DD D6 4E 3B </deviceId>
#<timestamp type="DateTime">2016-04-13T06:24:39Z</timestamp>
#<value type="Double">26.250000</value>
#<unit type="String">C</unit>
#</Measurement>

Data Store created and added successfully

Published successfully
