
(cl:in-package :asdf)

(defsystem "tension_m-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "tension" :depends-on ("_package_tension"))
    (:file "_package_tension" :depends-on ("_package"))
  ))