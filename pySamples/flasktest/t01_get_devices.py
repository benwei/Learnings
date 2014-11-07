#!/usr/bin/env python

from flask import Flask, request
from flask.ext.restful import reqparse, abort, Api, Resource

parser = reqparse.RequestParser()
parser.add_argument('info', type=str)

app = Flask(__name__)
api = Api(app)

devices = {}

class Device(Resource):
    def get(self, device_id):
        return {device_id: devices[device_id]}

    def put(self, device_id):
        args = parser.parse_args()
        info = {'info': args['info']}
        devices[device_id] = info
        return {device_id: devices[device_id]}

groups = {};

class DevicesGetCount(Resource):
    def get(self):
        return {'count': len(devices.keys())}

class DeviceList(Resource):
    def get(self):
        return devices

    def post(self):
        args = parser.parse_args()
        device_id = 'device%d' % (len(devices) + 1)
        devices[device_id] = {'info': args['info']}
        return devices[device_id], 201

class DevicesGroups(Resource):
    def get(self):
        return groups;
    def post(self):
        args = parser.parse_args()
        group_id = 'group%d' % (len(groups) + 1)
        groups[group_id] = {'devices': args['deviecs']}
        return {"group_id": group_id}, 201

api.add_resource(DevicesGetCount, '/devices/count')
api.add_resource(DeviceList,      '/devices')
api.add_resource(Device,          '/devices/<string:device_id>')
api.add_resource(DevicesGroups,   '/groups')

if __name__ == '__main__':
    kwargs = {"host": "0.0.0.0",
              "port": bconfig.port
             }
    app.run(debug=True, host="0.0.0.0")
