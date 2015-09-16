(defmodule MAIN (export ?ALL))
(defrule imprimeHola
	?h<-(initial-fact)	
	=>
	(retract ?h)
	(assert (initial-fact))
	(printout t "Hola, soy el modulo MAIN" crlf)
	(focus A B C)
)

(defmodule A (import MAIN ?ALL))
(defrule imprimeHola_A
	=>
	(printout t "Hola, soy el modulo A" crlf))


(defmodule B (import MAIN ?ALL))
(defrule imprimeHola_B
	=>
	(printout t "Hola, soy el modulo B" crlf))

(defmodule C (import MAIN ?ALL))
(defrule imprimeHola_C
	=>
	(printout t "Hola, soy el modulo C" crlf))

(set-current module A);Se vuelve a modificar en el modulo A, cambio de modulo