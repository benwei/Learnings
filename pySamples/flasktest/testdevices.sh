curl http://localhost:5000/devices/nas1 -d "info=Remember the milk" -X PUT
curl http://localhost:5000/devices/nas1
curl http://localhost:5000/devices/nas2 -d "info=Change my brakepads" -X PUT
curl http://localhost:5000/devices/nas2
curl http://localhost:5000/devices
curl http://localhost:5000/devices/count
#curl http://localhost:5000/groups -d ""
curl http://localhost:5000/devices -d "info=new add by devices" -X POST
curl http://localhost:5000/devices
