(deffacts ejer13 (dato 8)(dato 1)(dato 5)(dato verde)(dato 45)(todos-datos))

(defrule insertaOrden
?d<-(dato ?x&:(numberp ?x))
?v<-(todos-datos $?valores)
;(not (and (dato ?y&:(numberp ?y)&:(< ?y ?x))
;	(not(todos-datos $? ?y $?))
;))
;El comentario equivale al forall
(forall 
	(dato ?y&:(numberp ?y)&:(< ?y ?x)) 
	(todos-datos $? ?y $?)
)
(not (todos-datos $? ?x $?))
=>
(retract ?v)
(assert(todos-datos $?valores ?x))
)
