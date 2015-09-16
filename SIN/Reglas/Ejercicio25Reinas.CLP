(defmodule MAIN (export ?ALL))
(deftemplate reina 
	(slot id)
	(slot fil (allowed-values 1 2 3 4 5 6 7 8))
	(slot col (allowed-values 1 2 3 4 5 6 7 8))
)

(deftemplate tablero
	(slot id)
	(multislot reinas)
)

(defrule empiezaEsto
	=>
	(focus INICIALIZACION  ITERA_EN_FRONTERA IMPRIMESOLUCION )
)


(defmodule INICIALIZACION (import MAIN ?ALL) (export ?ALL))
(deffacts valoresIniciales
	;version antigua
	;(fil 1)(fil 2)(fil 3)(fil 4)(fil 5)(fil 6)(fil 7)(fil 8)
	;(col 1)(col 2)(col 3)(col 4)(col 5)(col 6)(col 7)(col 8)
	(tamanioTablero 8)
	(pos 1)
	(nextIdReina 1)
	(nextIdTablero 1)
	(tablero (id 0)(reinas))
	(frontera 0)
	(actual 0)
)

(defrule creaPosicion
	(pos ?x)
	(tamanioTablero ?y)
	(test (< ?x ?y))
	=>
	(assert (pos (+ ?x 1)))

)

(defmodule ITERA_EN_FRONTERA(import MAIN ?ALL)(import INICIALIZACION ?ALL))
(defrule eliminaActual
	?h<-(actual ?)
	=>
	(retract ?h)
)

(defrule reglaIteraFrontera
	;Encontrar el tablero solucion
	(tamanioTablero ?tamanioTablero)
	(not (and 
		(tablero (id ?idTablero)(reinas $?reinas))
		(test (= ?tamanioTablero(length $?reinas)))))
	?h<-(frontera ?x $?resto)
	(not (actual ?))
	=>
	(retract ?h)
	(assert (frontera $?resto))
	(assert (actual ?x))
	(focus GENERA_HIJOS)
)

(defmodule GENERA_HIJOS (import MAIN ?ALL)(import INICIALIZACION ?ALL))

(deffunction se-atacan 
	(?f ?c ?f2 ?c2)
	(if (or
		(= ?f ?f2)
		(= ?c ?c2)
		(= (+ ?f ?c)(+ ?f2 ?c2))
		(= (- ?f ?c)(- ?f2 ?c2))
		)
	then TRUE
	else FALSE
	)
)

(defrule generaUnHijoSuponiendoQueExisteLaReina
	(actual ?x)
	(tablero (id ?x)(reinas $?reinas))
	?h<-(frontera $?nodos)
	?h2<-(nextIdTablero ?nuevoIdTablero)
	(pos ?f)
	(pos ?c)
	(test (= ?f (+ (length $?reinas) 1)))
	(reina (id ?idReina)(fil ?f)(col ?c))
	(not (and (tablero (id ?y&~?x))
		(forall (tablero(id ?x)(reinas $? ?unaReina $?))
			(tablero (id ?y) (reinas $? ?unaReina $?))
		)
		(tablero (id ?y)(reinas $? ?idReina $?))
		)
	)


	(forall (and
			(tablero (id ?x)(reinas $? ?unaReina $?))
			(reina (id ?unaReina)(fil ?f2)(col ?c2))
		)
			(not (test(se-atacan ?f ?c ?f2 ?c2))))
	=>
	(assert(tablero(id ?nuevoIdTablero)(reinas $?reinas ?idReina)))
	(retract ?h ?h2)
	(assert (frontera ?nuevoIdTablero $?nodos))
	(assert (nextIdTablero (+ ?nuevoIdTablero 1)))
	
)	

(defrule generaUnHijoSuponiendoQueNoExisteLaReina
	(actual ?x)
	(tablero (id ?x)(reinas $?reinas))
	?h<-(frontera $?nodos)
	?h2<-(nextIdTablero ?nuevoIdTablero)
	?h3<-(nextIdReina ?nuevoIdReina)
	(pos ?f)
	(pos ?c)
	(test (= ?f (+ (length $?reinas) 1)))
	(not (reina (id ?idReina)(fil ?f)(col ?c)))
	(forall (and
			(tablero (id ?x)(reinas $? ?unaReina $?))
			(reina (id ?unaReina)(fil ?f2)(col ?c2))
		)
			(not (test (se-atacan ?f ?c ?f2 ?c2))))
	=>
	(assert (reina (id ?nuevoIdReina)(fil ?f)(col ?c)))
	(assert(tablero(id ?nuevoIdTablero)(reinas $?reinas ?nuevoIdReina)))
	(retract ?h ?h2 ?h3)
	(assert (frontera ?nuevoIdTablero $?nodos))
	(assert (nextIdTablero (+ ?nuevoIdTablero 1)))
	(assert	(nextIdReina (+ ?nuevoIdReina 1)))
)

(defmodule IMPRIMESOLUCION (import MAIN ?ALL)(import INICIALIZACION ?ALL))
(defrule imprimeSolucion
	;Encontrar el tablero solucion
	(tamanioTablero ?tamanioTablero)
	(tablero (id ?idTablero)(reinas $?reinas))
	(test (= ?tamanioTablero(length $?reinas)))
	
	;Seleccionar una reina de ese tablero
	(tablero (id ?idTablero)(reinas $? ?unaReina $?))
	(reina (id ?unaReina)(fil ?f)(col ?c))
	=>
	(printout t ?f " : " ?c crlf)
)


;************************************************************************************


;funcion para la practica anterior

(deffunction se-atacan 
	(?f ?c ?f2 ?c2)
	(if (or
		(= ?f ?f2)
		(= ?c ?c2)
		(= (+ ?f ?c)(+ ?f2 ?c2))
		(= (- ?f ?c)(- ?f2 ?c2))
		)
	then TRUE
	else FALSE
	)
)


;Regla que no funciona bien

(defrule posicionNuevaReina
(fil ?f)
(col ?c)
;(not (reina (fil ?f))); No puede ser en la misma fila
;(not (reina (col ?c))); No puede ser en la misma columna
;(not (and (reina (fil ?f2)(col ?c2)) 
;		(test 
;			(= (+ ?f ?c)(+ ?f2 ?c2))
;		)
;	)
;)
;(not (and (reina (fil ?f2)(col ?c2)) 
;		(test 
;			(= (- ?f ?c)(- ?f2 ?c2))
;		)
;	)
;)
;Representa todo lo anterior con la funcion se-atacan
(not (and 
	(reina (fil ?f2)(col ?c2))
	(test (se-atacan ?f ?c ?f2 ?c2))
	)
)
=>
(assert (reina (fil ?f)(col ?c)) )
)

;***********************************************************************



;Solucion para 4 reinas, pero no es eficiente

(deffacts tablero2
	(fil 1)(fil 2)(fil 3)(fil 4)
	(col 1)(col 2)(col 3)(col 4)
)

(defrule posicionNuevaReina2
(fil ?f)
(col ?c)
=>
(assert (reina (fil ?f)(col ?c)) )
)

;Da la solucion de forma cutre para 4 reinas

(defrule dameSolucion
	(reina (fil ?f1)(col ?c1))
	(reina (fil ?f2)(col ?c2))
	(reina (fil ?f3)(col ?c3))
	(reina (fil ?f4)(col ?c4))
	(not (test (se-atacan ?f1 ?c1 ?f2 ?c2)))
	(not (test (se-atacan ?f1 ?c1 ?f3 ?c3)))
	(not (test (se-atacan ?f1 ?c1 ?f4 ?c4)))
	(not (test (se-atacan ?f2 ?c2 ?f3 ?c3)))
	(not (test (se-atacan ?f2 ?c2 ?f4 ?c4)))
	(not (test (se-atacan ?f3 ?c3 ?f4 ?c4)))
=>
	(printout t "La solucion es: " crlf
	?f1 ", " ?c1 crlf
	?f2 ", " ?c2 crlf
	?f3 ", " ?c3 crlf
	?f4 ", " ?c4 crlf
	)

)