"""autogenerated by genpy from sr_grasp_msgs/ForceControlFeedback.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import geometry_msgs.msg

class ForceControlFeedback(genpy.Message):
  _md5sum = "c2c88f3d072d22e6edb0af4767beecd3"
  _type = "sr_grasp_msgs/ForceControlFeedback"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======
# Feedback
# State shows what the node is currently doing.
float64 current_state #current normal force
geometry_msgs/Vector3 normal #current normal direction
geometry_msgs/Vector3 tangential #current tangential direction


================================================================================
MSG: geometry_msgs/Vector3
# This represents a vector in free space. 

float64 x
float64 y
float64 z
"""
  __slots__ = ['current_state','normal','tangential']
  _slot_types = ['float64','geometry_msgs/Vector3','geometry_msgs/Vector3']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       current_state,normal,tangential

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(ForceControlFeedback, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.current_state is None:
        self.current_state = 0.
      if self.normal is None:
        self.normal = geometry_msgs.msg.Vector3()
      if self.tangential is None:
        self.tangential = geometry_msgs.msg.Vector3()
    else:
      self.current_state = 0.
      self.normal = geometry_msgs.msg.Vector3()
      self.tangential = geometry_msgs.msg.Vector3()

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_struct_7d.pack(_x.current_state, _x.normal.x, _x.normal.y, _x.normal.z, _x.tangential.x, _x.tangential.y, _x.tangential.z))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.normal is None:
        self.normal = geometry_msgs.msg.Vector3()
      if self.tangential is None:
        self.tangential = geometry_msgs.msg.Vector3()
      end = 0
      _x = self
      start = end
      end += 56
      (_x.current_state, _x.normal.x, _x.normal.y, _x.normal.z, _x.tangential.x, _x.tangential.y, _x.tangential.z,) = _struct_7d.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_struct_7d.pack(_x.current_state, _x.normal.x, _x.normal.y, _x.normal.z, _x.tangential.x, _x.tangential.y, _x.tangential.z))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.normal is None:
        self.normal = geometry_msgs.msg.Vector3()
      if self.tangential is None:
        self.tangential = geometry_msgs.msg.Vector3()
      end = 0
      _x = self
      start = end
      end += 56
      (_x.current_state, _x.normal.x, _x.normal.y, _x.normal.z, _x.tangential.x, _x.tangential.y, _x.tangential.z,) = _struct_7d.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_7d = struct.Struct("<7d")
