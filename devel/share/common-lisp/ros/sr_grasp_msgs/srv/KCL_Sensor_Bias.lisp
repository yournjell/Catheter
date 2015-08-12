; Auto-generated. Do not edit!


(cl:in-package sr_grasp_msgs-srv)


;//! \htmlinclude KCL_Sensor_Bias-request.msg.html

(cl:defclass <KCL_Sensor_Bias-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass KCL_Sensor_Bias-request (<KCL_Sensor_Bias-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <KCL_Sensor_Bias-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'KCL_Sensor_Bias-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name sr_grasp_msgs-srv:<KCL_Sensor_Bias-request> is deprecated: use sr_grasp_msgs-srv:KCL_Sensor_Bias-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <KCL_Sensor_Bias-request>) ostream)
  "Serializes a message object of type '<KCL_Sensor_Bias-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <KCL_Sensor_Bias-request>) istream)
  "Deserializes a message object of type '<KCL_Sensor_Bias-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<KCL_Sensor_Bias-request>)))
  "Returns string type for a service object of type '<KCL_Sensor_Bias-request>"
  "sr_grasp_msgs/KCL_Sensor_BiasRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'KCL_Sensor_Bias-request)))
  "Returns string type for a service object of type 'KCL_Sensor_Bias-request"
  "sr_grasp_msgs/KCL_Sensor_BiasRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<KCL_Sensor_Bias-request>)))
  "Returns md5sum for a message object of type '<KCL_Sensor_Bias-request>"
  "06d4f276c51f7469624c6fbcbf0e7869")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'KCL_Sensor_Bias-request)))
  "Returns md5sum for a message object of type 'KCL_Sensor_Bias-request"
  "06d4f276c51f7469624c6fbcbf0e7869")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<KCL_Sensor_Bias-request>)))
  "Returns full string definition for message of type '<KCL_Sensor_Bias-request>"
  (cl:format cl:nil "~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'KCL_Sensor_Bias-request)))
  "Returns full string definition for message of type 'KCL_Sensor_Bias-request"
  (cl:format cl:nil "~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <KCL_Sensor_Bias-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <KCL_Sensor_Bias-request>))
  "Converts a ROS message object to a list"
  (cl:list 'KCL_Sensor_Bias-request
))
;//! \htmlinclude KCL_Sensor_Bias-response.msg.html

(cl:defclass <KCL_Sensor_Bias-response> (roslisp-msg-protocol:ros-message)
  ((reply
    :reader reply
    :initarg :reply
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass KCL_Sensor_Bias-response (<KCL_Sensor_Bias-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <KCL_Sensor_Bias-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'KCL_Sensor_Bias-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name sr_grasp_msgs-srv:<KCL_Sensor_Bias-response> is deprecated: use sr_grasp_msgs-srv:KCL_Sensor_Bias-response instead.")))

(cl:ensure-generic-function 'reply-val :lambda-list '(m))
(cl:defmethod reply-val ((m <KCL_Sensor_Bias-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-srv:reply-val is deprecated.  Use sr_grasp_msgs-srv:reply instead.")
  (reply m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <KCL_Sensor_Bias-response>) ostream)
  "Serializes a message object of type '<KCL_Sensor_Bias-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'reply) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <KCL_Sensor_Bias-response>) istream)
  "Deserializes a message object of type '<KCL_Sensor_Bias-response>"
    (cl:setf (cl:slot-value msg 'reply) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<KCL_Sensor_Bias-response>)))
  "Returns string type for a service object of type '<KCL_Sensor_Bias-response>"
  "sr_grasp_msgs/KCL_Sensor_BiasResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'KCL_Sensor_Bias-response)))
  "Returns string type for a service object of type 'KCL_Sensor_Bias-response"
  "sr_grasp_msgs/KCL_Sensor_BiasResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<KCL_Sensor_Bias-response>)))
  "Returns md5sum for a message object of type '<KCL_Sensor_Bias-response>"
  "06d4f276c51f7469624c6fbcbf0e7869")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'KCL_Sensor_Bias-response)))
  "Returns md5sum for a message object of type 'KCL_Sensor_Bias-response"
  "06d4f276c51f7469624c6fbcbf0e7869")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<KCL_Sensor_Bias-response>)))
  "Returns full string definition for message of type '<KCL_Sensor_Bias-response>"
  (cl:format cl:nil "~%bool reply~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'KCL_Sensor_Bias-response)))
  "Returns full string definition for message of type 'KCL_Sensor_Bias-response"
  (cl:format cl:nil "~%bool reply~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <KCL_Sensor_Bias-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <KCL_Sensor_Bias-response>))
  "Converts a ROS message object to a list"
  (cl:list 'KCL_Sensor_Bias-response
    (cl:cons ':reply (reply msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'KCL_Sensor_Bias)))
  'KCL_Sensor_Bias-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'KCL_Sensor_Bias)))
  'KCL_Sensor_Bias-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'KCL_Sensor_Bias)))
  "Returns string type for a service object of type '<KCL_Sensor_Bias>"
  "sr_grasp_msgs/KCL_Sensor_Bias")