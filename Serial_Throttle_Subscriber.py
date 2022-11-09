import sys
import time

import ecal.core.core as ecal_core
from ecal.core.subscriber import StringSubscriber


class eCAL_Interface:
	def __init__(self):

		#add this 
		self.throttle = 0  # 0 = zero, 1=full

		def throttle_cb(topic_name, msg, time):
			global eCAL_Command
			eCAL_Command.throttle = float(msg)

		ecal_core.initialize(sys.argv, "carla")
		#self._pub = StringPublisher("Carla")

		# sub_hmican = ProtoSubscriber("HmiCanKeyboardStatePb", HMICanKeyboard_pb2.HmiCanKeyboardState)
		# sub_hmican.set_callback(can_callback)
		#sub_brake = ProtoSubscriber("BrakeInPb", Brake_pb2.Brake)
		#sub_brake.set_callback(brake_cb)
		#sub_steering = ProtoSubscriber("VehicleDynamicsInPb", VehicleDynamics_pb2.VehicleDynamics)
		#sub_steering.set_callback(steering_cb)


		#also add this!!!!!!
		sub_throttle = StringSubscriber("SerialThrottleString")
		sub_throttle.set_callback(throttle_cb)


eCAL_Command = eCAL_Interface()


# Callback for receiving messages



if __name__ == "__main__":
	# Initialize eCAL & eCAL_Interface


	# Just don't exit
	while ecal_core.ok():
		time.sleep(0.25)
		#use this line later
		print(eCAL_Command.throttle)

	# finalize eCAL API
	ecal_core.finalize()
