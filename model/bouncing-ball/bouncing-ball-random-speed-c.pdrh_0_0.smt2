(set-logic QF_NRA_ODE)
(declare-fun v0 () Real)
(declare-fun t () Real)
(declare-fun Sy () Real)
(declare-fun Sx () Real)
(declare-fun v0_0_0 () Real)
(declare-fun v0_0_t () Real)
(declare-fun t_0_0 () Real)
(declare-fun t_0_t () Real)
(declare-fun Sy_0_0 () Real)
(declare-fun Sy_0_t () Real)
(declare-fun Sx_0_0 () Real)
(declare-fun Sx_0_t () Real)
(declare-fun time_0 () Real)
(declare-fun mode_0 () Real)
(define-ode flow_1 ((= d/dt[Sx] (* v0 (cos 0.7854))) (= d/dt[Sy] (- (* v0 (sin 0.7854)) (* 9.8 t))) (= d/dt[t] 1) (= d/dt[v0] 0)))
(assert (<= -10 v0_0_0))
(assert (<= v0_0_0 50))
(assert (<= -10 v0_0_t))
(assert (<= v0_0_t 50))
(assert (<= 0 t_0_0))
(assert (<= t_0_0 15))
(assert (<= 0 t_0_t))
(assert (<= t_0_t 15))
(assert (<= 0 Sy_0_0))
(assert (<= Sy_0_0 100))
(assert (<= 0 Sy_0_t))
(assert (<= Sy_0_t 100))
(assert (<= 0 Sx_0_0))
(assert (<= Sx_0_0 1000))
(assert (<= 0 Sx_0_t))
(assert (<= Sx_0_t 1000))
(assert (<= 0 time_0 [0.000000]))
(assert (<= time_0 15 [0.000000]))
(assert (<= 1 mode_0))
(assert (<= mode_0 1))
(assert (and (and (>= v0_0_0 31.305) (<= v0_0_0 31.305) (= t_0_0 0) (= Sy_0_0 0) (= Sx_0_0 0)) (= mode_0 1) (= [v0_0_t t_0_t Sy_0_t Sx_0_t] (integral 0. time_0 [v0_0_0 t_0_0 Sy_0_0 Sx_0_0] flow_1)) (= mode_0 1) (forall_t 1 [0 time_0] (< Sx_0_t 100)) (< Sx_0_t 100) (< Sx_0_0 100) (= mode_0 1) (> t_0_t 0.0001) (<= Sy_0_t 0)))
(check-sat)
(exit)
