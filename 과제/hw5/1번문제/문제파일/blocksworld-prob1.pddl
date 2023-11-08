;; problem file: blocksword-prob1.pddl

(define (problem blocksword-prob1)
    (:domain blocksworld)
    (:objects a b c d e f)
    (:init (on-table a) (on-table d) (on-table f) 
           (clear c) (clear e) (clear f) (on b a) (on c b) (on e d) (arm-empty))
    (:goal (and (on c f) (on d c) (on e a))))