#pragma once
#include <cstdarg>
namespace Eloquent {
    namespace ML {
        namespace Port {
            class RandomForestModel {
                public:
                    /**
                    * Predict class for features vector
                    */
                    int predict(float *x) {
                        uint8_t votes[3] = { 0 };
                        // tree #1
                        if (x[1] <= 17.059999465942383) {
                            if (x[0] <= 1676.5) {
                                if (x[1] <= 15.5) {
                                    if (x[1] <= 13.5) {
                                        if (x[1] <= 8.5) {
                                            if (x[0] <= 426.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            if (x[0] <= 314.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                if (x[1] <= 10.5) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    if (x[1] <= 12.5) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        if (x[0] <= 1194.5) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }

                                    else {
                                        if (x[0] <= 320.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }

                                else {
                                    if (x[1] <= 16.994999885559082) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[0] <= 949.0) {
                                            if (x[0] <= 298.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[1] <= 14.96500015258789) {
                                    votes[2] += 1;
                                }

                                else {
                                    if (x[0] <= 2023.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[1] <= 16.5) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            votes[2] += 1;
                                        }
                                    }
                                }
                            }
                        }

                        else {
                            if (x[0] <= 299.0) {
                                if (x[0] <= 220.0) {
                                    if (x[0] <= 1.5) {
                                        if (x[1] <= 21.06999969482422) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }

                                else {
                                    if (x[0] <= 222.5) {
                                        if (x[1] <= 20.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }

                                    else {
                                        if (x[1] <= 21.22000026702881) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[0] <= 268.0) {
                                                if (x[0] <= 256.5) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    votes[0] += 1;
                                                }
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[1] <= 20.199999809265137) {
                                    if (x[0] <= 1557.5) {
                                        if (x[0] <= 1104.5) {
                                            if (x[0] <= 1025.0) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            if (x[0] <= 1485.5) {
                                                if (x[0] <= 1215.0) {
                                                    if (x[1] <= 20.030000686645508) {
                                                        if (x[1] <= 19.920000076293945) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            if (x[0] <= 1171.0) {
                                                                if (x[0] <= 1137.0) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        votes[2] += 1;
                                                    }
                                                }

                                                else {
                                                    if (x[0] <= 1460.0) {
                                                        if (x[1] <= 19.229999542236328) {
                                                            if (x[0] <= 1391.5) {
                                                                if (x[0] <= 1312.0) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    if (x[0] <= 1377.0) {
                                                                        if (x[1] <= 17.770000457763672) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 17.795000076293945) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }

                                                        else {
                                                            if (x[1] <= 19.9950008392334) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                if (x[0] <= 1276.5) {
                                                                    if (x[1] <= 20.0600004196167) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 19.385000228881836) {
                                                            if (x[1] <= 17.860000610351562) {
                                                                if (x[0] <= 1482.0) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 1475.0) {
                                                                if (x[0] <= 1467.0) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[1] <= 18.41999912261963) {
                                                    if (x[1] <= 17.84000015258789) {
                                                        if (x[0] <= 1524.0) {
                                                            if (x[0] <= 1497.0) {
                                                                votes[0] += 1;
                                                            }

                                                            else {
                                                                if (x[0] <= 1510.0) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    if (x[0] <= 1519.0) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 1526.5) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                if (x[0] <= 1529.5) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    if (x[1] <= 17.8149995803833) {
                                                                        if (x[1] <= 17.729999542236328) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1531.5) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                if (x[1] <= 17.789999961853027) {
                                                                                    if (x[1] <= 17.75) {
                                                                                        if (x[0] <= 1534.5) {
                                                                                            votes[1] += 1;
                                                                                        }

                                                                                        else {
                                                                                            votes[1] += 1;
                                                                                        }
                                                                                    }

                                                                                    else {
                                                                                        votes[1] += 1;
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 1487.5) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            if (x[0] <= 1534.5) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                if (x[0] <= 1545.0) {
                                                                    if (x[1] <= 18.050000190734863) {
                                                                        if (x[1] <= 18.010000228881836) {
                                                                            if (x[1] <= 17.910000801086426) {
                                                                                if (x[1] <= 17.860000610351562) {
                                                                                    votes[2] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[1] <= 20.114999771118164) {
                                                        if (x[0] <= 1554.5) {
                                                            if (x[1] <= 20.010000228881836) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                if (x[0] <= 1496.0) {
                                                                    if (x[0] <= 1494.5) {
                                                                        if (x[1] <= 20.030000686645508) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 1556.5) {
                                                                if (x[1] <= 19.93000030517578) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 1544.0) {
                                                            if (x[0] <= 1502.0) {
                                                                if (x[1] <= 20.139999389648438) {
                                                                    if (x[0] <= 1498.5) {
                                                                        if (x[0] <= 1496.0) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[0] <= 1494.5) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1498.0) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1508.0) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    if (x[0] <= 1509.5) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1533.0) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[1] <= 20.15999984741211) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                if (x[1] <= 20.18000030517578) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1] <= 19.449999809265137) {
                                            if (x[0] <= 2646.0) {
                                                if (x[1] <= 17.96500015258789) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    if (x[1] <= 18.010000228881836) {
                                                        if (x[0] <= 2268.5) {
                                                            if (x[1] <= 17.989999771118164) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 2309.5) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                if (x[0] <= 2622.5) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 2530.5) {
                                                            if (x[1] <= 18.920000076293945) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                if (x[1] <= 19.06999969482422) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 2609.5) {
                                                                if (x[0] <= 2607.5) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    if (x[0] <= 2608.5) {
                                                                        if (x[1] <= 19.329999923706055) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 19.329999923706055) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                if (x[1] <= 18.40499973297119) {
                                                                    if (x[0] <= 2620.5) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[1] <= 18.854999542236328) {
                                                    if (x[1] <= 17.890000343322754) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        if (x[0] <= 2773.5) {
                                                            if (x[1] <= 18.164999961853027) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }
                                                }

                                                else {
                                                    votes[2] += 1;
                                                }
                                            }
                                        }

                                        else {
                                            if (x[0] <= 1776.0) {
                                                if (x[1] <= 20.114999771118164) {
                                                    if (x[0] <= 1602.5) {
                                                        if (x[1] <= 20.06999969482422) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            if (x[1] <= 20.09000015258789) {
                                                                if (x[0] <= 1585.5) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1584.5) {
                                                                    if (x[0] <= 1574.0) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 19.96500015258789) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[0] <= 1584.5) {
                                                        if (x[1] <= 20.15999984741211) {
                                                            if (x[0] <= 1575.5) {
                                                                if (x[1] <= 20.139999389648438) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[1] <= 20.139999389648438) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 1562.5) {
                                                                if (x[0] <= 1559.5) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 20.15999984741211) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            if (x[0] <= 1587.5) {
                                                                if (x[0] <= 1586.5) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[1] <= 20.050000190734863) {
                                                    if (x[1] <= 19.469999313354492) {
                                                        if (x[0] <= 2617.5) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }

                                                    else {
                                                        votes[2] += 1;
                                                    }
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[0] <= 1130.0) {
                                        if (x[1] <= 20.979999542236328) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            if (x[1] <= 22.515000343322754) {
                                                if (x[1] <= 21.860000610351562) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    if (x[0] <= 840.0) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        if (x[0] <= 854.0) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[0] <= 764.5) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1] <= 23.489999771118164) {
                                            if (x[0] <= 1553.5) {
                                                if (x[1] <= 20.244999885559082) {
                                                    if (x[0] <= 1347.0) {
                                                        votes[2] += 1;
                                                    }

                                                    else {
                                                        if (x[0] <= 1512.0) {
                                                            if (x[0] <= 1505.5) {
                                                                if (x[1] <= 20.219999313354492) {
                                                                    if (x[0] <= 1502.5) {
                                                                        if (x[0] <= 1499.0) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[0] <= 1503.5) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1508.5) {
                                                                    if (x[1] <= 20.219999313354492) {
                                                                        if (x[0] <= 1506.5) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[1] <= 20.219999313354492) {
                                                                if (x[0] <= 1532.5) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1534.5) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[1] <= 21.015000343322754) {
                                                        if (x[0] <= 1501.5) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            if (x[0] <= 1505.5) {
                                                                if (x[1] <= 20.270000457763672) {
                                                                    if (x[0] <= 1503.5) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[0] <= 1503.5) {
                                                                        if (x[1] <= 20.289999961853027) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1502.5) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                if (x[1] <= 20.425000190734863) {
                                                                                    votes[2] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1552.5) {
                                                                    if (x[0] <= 1524.5) {
                                                                        if (x[1] <= 20.350000381469727) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1521.0) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 21.699999809265137) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[0] <= 3991.5) {
                                                    if (x[0] <= 1626.5) {
                                                        if (x[0] <= 1587.5) {
                                                            if (x[1] <= 20.854999542236328) {
                                                                if (x[0] <= 1554.5) {
                                                                    if (x[1] <= 20.3100004196167) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[1] <= 21.515000343322754) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[1] <= 20.3100004196167) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                if (x[1] <= 21.52500057220459) {
                                                                    if (x[0] <= 1588.5) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 23.469999313354492) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[1] <= 23.44499969482422) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        votes[2] += 1;
                                                    }
                                                }
                                            }
                                        }

                                        else {
                                            if (x[0] <= 2967.0) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                if (x[1] <= 24.010000228881836) {
                                                    if (x[1] <= 23.989999771118164) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        if (x[0] <= 3762.0) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #2
                        if (x[0] <= 299.5) {
                            if (x[0] <= 262.5) {
                                if (x[0] <= 1.0) {
                                    if (x[1] <= 21.015000343322754) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[1] <= 21.59000015258789) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }

                            else {
                                if (x[0] <= 264.0) {
                                    if (x[1] <= 20.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        else {
                            if (x[0] <= 1129.0) {
                                if (x[1] <= 22.570000648498535) {
                                    if (x[0] <= 1104.5) {
                                        if (x[0] <= 718.0) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            if (x[0] <= 721.0) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                if (x[0] <= 774.0) {
                                                    if (x[1] <= 20.69499969482422) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }

                                                else {
                                                    if (x[0] <= 954.5) {
                                                        if (x[0] <= 952.0) {
                                                            if (x[1] <= 21.860000610351562) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                if (x[0] <= 848.5) {
                                                                    if (x[1] <= 21.895000457763672) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }
                                            }
                                        }
                                    }

                                    else {
                                        if (x[0] <= 1113.5) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            if (x[1] <= 21.204999923706055) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[0] <= 761.5) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[1] <= 17.079999923706055) {
                                    if (x[1] <= 16.265000343322754) {
                                        if (x[0] <= 2345.5) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            if (x[0] <= 2627.0) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1] <= 16.994999885559082) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[0] <= 1651.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                if (x[0] <= 2455.0) {
                                                    votes[2] += 1;
                                                }

                                                else {
                                                    if (x[1] <= 17.024999618530273) {
                                                        votes[2] += 1;
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[1] <= 20.199999809265137) {
                                        if (x[0] <= 1557.5) {
                                            if (x[1] <= 18.429999351501465) {
                                                if (x[1] <= 17.789999961853027) {
                                                    if (x[1] <= 17.75) {
                                                        if (x[0] <= 1447.0) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            if (x[1] <= 17.609999656677246) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                if (x[1] <= 17.65999984741211) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    if (x[0] <= 1492.5) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 17.729999542236328) {
                                                                            if (x[0] <= 1533.5) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                if (x[1] <= 17.710000038146973) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1534.5) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 1532.5) {
                                                            if (x[0] <= 1270.5) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                if (x[1] <= 17.770000457763672) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[0] <= 1534.5) {
                                                        if (x[0] <= 1176.5) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            if (x[1] <= 17.860000610351562) {
                                                                if (x[1] <= 17.84000015258789) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    if (x[0] <= 1480.5) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1486.0) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1487.5) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 1545.0) {
                                                            if (x[1] <= 17.90000057220459) {
                                                                if (x[1] <= 17.84000015258789) {
                                                                    if (x[1] <= 17.8149995803833) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[1] <= 17.860000610351562) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[0] <= 1208.0) {
                                                    if (x[1] <= 19.985000610351562) {
                                                        if (x[1] <= 19.910000801086426) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }

                                                    else {
                                                        votes[2] += 1;
                                                    }
                                                }

                                                else {
                                                    if (x[1] <= 19.199999809265137) {
                                                        if (x[0] <= 1473.0) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 1554.5) {
                                                            if (x[1] <= 19.989999771118164) {
                                                                if (x[0] <= 1237.0) {
                                                                    if (x[1] <= 19.824999809265137) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[1] <= 20.18000030517578) {
                                                                    if (x[1] <= 20.15999984741211) {
                                                                        if (x[0] <= 1268.5) {
                                                                            if (x[0] <= 1218.5) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[1] <= 20.09000015258789) {
                                                                                if (x[0] <= 1489.0) {
                                                                                    if (x[0] <= 1486.5) {
                                                                                        if (x[0] <= 1476.5) {
                                                                                            votes[1] += 1;
                                                                                        }

                                                                                        else {
                                                                                            votes[1] += 1;
                                                                                        }
                                                                                    }

                                                                                    else {
                                                                                        votes[1] += 1;
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                if (x[1] <= 20.139999389648438) {
                                                                                    if (x[1] <= 20.114999771118164) {
                                                                                        if (x[0] <= 1510.5) {
                                                                                            if (x[0] <= 1494.5) {
                                                                                                votes[1] += 1;
                                                                                            }

                                                                                            else {
                                                                                                if (x[0] <= 1498.0) {
                                                                                                    votes[1] += 1;
                                                                                                }

                                                                                                else {
                                                                                                    votes[1] += 1;
                                                                                                }
                                                                                            }
                                                                                        }

                                                                                        else {
                                                                                            if (x[0] <= 1519.0) {
                                                                                                votes[2] += 1;
                                                                                            }

                                                                                            else {
                                                                                                votes[1] += 1;
                                                                                            }
                                                                                        }
                                                                                    }

                                                                                    else {
                                                                                        if (x[0] <= 1491.5) {
                                                                                            votes[1] += 1;
                                                                                        }

                                                                                        else {
                                                                                            if (x[0] <= 1509.5) {
                                                                                                votes[2] += 1;
                                                                                            }

                                                                                            else {
                                                                                                votes[1] += 1;
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    if (x[0] <= 1520.5) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[1] += 1;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1492.0) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1500.0) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                if (x[0] <= 1521.0) {
                                                                                    if (x[0] <= 1504.5) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[1] += 1;
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[0] <= 1521.0) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 1556.5) {
                                                                if (x[1] <= 20.0600004196167) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[1] <= 20.09500026702881) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }

                                        else {
                                            if (x[0] <= 2617.5) {
                                                if (x[0] <= 1599.5) {
                                                    if (x[0] <= 1567.5) {
                                                        if (x[1] <= 20.09000015258789) {
                                                            if (x[1] <= 20.06999969482422) {
                                                                if (x[1] <= 18.80500030517578) {
                                                                    if (x[1] <= 17.824999809265137) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 1561.5) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                if (x[0] <= 1562.5) {
                                                                    if (x[1] <= 20.139999389648438) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 20.114999771118164) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            if (x[1] <= 20.18000030517578) {
                                                                if (x[1] <= 20.15999984741211) {
                                                                    if (x[1] <= 20.139999389648438) {
                                                                        if (x[0] <= 1585.5) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1585.5) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[0] <= 1583.5) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1586.5) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1587.5) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1587.5) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[1] <= 19.449999809265137) {
                                                        if (x[1] <= 17.989999771118164) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            if (x[0] <= 2545.5) {
                                                                if (x[1] <= 18.020000457763672) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    if (x[1] <= 18.920000076293945) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 19.06999969482422) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                if (x[1] <= 19.43000030517578) {
                                                                    if (x[1] <= 18.394999504089355) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 19.34000015258789) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 2612.5) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[0] <= 2614.5) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 20.020000457763672) {
                                                            if (x[1] <= 19.890000343322754) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                if (x[1] <= 19.96500015258789) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    if (x[0] <= 1756.5) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[1] <= 19.469999313354492) {
                                                    if (x[1] <= 18.979999542236328) {
                                                        if (x[1] <= 18.010000228881836) {
                                                            if (x[1] <= 17.989999771118164) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                if (x[0] <= 2625.0) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 2643.5) {
                                                            if (x[0] <= 2638.0) {
                                                                if (x[0] <= 2618.5) {
                                                                    if (x[1] <= 19.449999809265137) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 2719.5) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }
                                                    }
                                                }

                                                else {
                                                    votes[2] += 1;
                                                }
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1] <= 23.489999771118164) {
                                            if (x[0] <= 1554.5) {
                                                if (x[1] <= 20.270000457763672) {
                                                    if (x[1] <= 20.219999313354492) {
                                                        if (x[0] <= 1347.0) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            if (x[0] <= 1501.5) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                if (x[0] <= 1503.5) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    if (x[0] <= 1506.5) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1527.5) {
                                                                            if (x[0] <= 1511.5) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 20.244999885559082) {
                                                            if (x[0] <= 1522.5) {
                                                                if (x[0] <= 1502.0) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    if (x[0] <= 1505.0) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 1504.5) {
                                                                if (x[0] <= 1501.5) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    if (x[0] <= 1503.5) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1534.5) {
                                                                    if (x[0] <= 1506.0) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[0] <= 1544.0) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[0] <= 1184.0) {
                                                        if (x[1] <= 21.710000038146973) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 1263.0) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            if (x[1] <= 21.015000343322754) {
                                                                if (x[0] <= 1501.5) {
                                                                    if (x[0] <= 1386.5) {
                                                                        if (x[1] <= 20.890000343322754) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[1] <= 20.5) {
                                                                        if (x[1] <= 20.479999542236328) {
                                                                            if (x[1] <= 20.394999504089355) {
                                                                                if (x[0] <= 1502.5) {
                                                                                    votes[2] += 1;
                                                                                }

                                                                                else {
                                                                                    if (x[1] <= 20.369999885559082) {
                                                                                        votes[2] += 1;
                                                                                    }

                                                                                    else {
                                                                                        if (x[0] <= 1544.0) {
                                                                                            votes[2] += 1;
                                                                                        }

                                                                                        else {
                                                                                            if (x[0] <= 1553.5) {
                                                                                                votes[1] += 1;
                                                                                            }

                                                                                            else {
                                                                                                votes[2] += 1;
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1528.5) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                if (x[1] <= 21.494999885559082) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[1] <= 23.434999465942383) {
                                                    if (x[1] <= 21.449999809265137) {
                                                        if (x[1] <= 21.03499984741211) {
                                                            if (x[0] <= 1587.5) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                if (x[1] <= 20.219999313354492) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 3844.5) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }
                                                }

                                                else {
                                                    votes[2] += 1;
                                                }
                                            }
                                        }

                                        else {
                                            if (x[1] <= 24.81999969482422) {
                                                if (x[1] <= 24.010000228881836) {
                                                    if (x[0] <= 3648.0) {
                                                        if (x[0] <= 2967.0) {
                                                            if (x[0] <= 1230.0) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 3370.0) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 4084.5) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            if (x[1] <= 23.520000457763672) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }
                                                    }
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #3
                        if (x[0] <= 299.5) {
                            if (x[1] <= 21.09000015258789) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[1] <= 21.72000026702881) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        else {
                            if (x[1] <= 17.059999465942383) {
                                if (x[0] <= 1185.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[1] <= 16.265000343322754) {
                                        if (x[0] <= 2455.0) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            if (x[0] <= 2627.0) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[0] <= 2238.5) {
                                            if (x[0] <= 1676.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                if (x[1] <= 16.96500015258789) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    votes[2] += 1;
                                                }
                                            }
                                        }

                                        else {
                                            votes[2] += 1;
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[1] <= 20.18000030517578) {
                                    if (x[1] <= 17.789999961853027) {
                                        if (x[1] <= 17.770000457763672) {
                                            if (x[1] <= 17.130000114440918) {
                                                if (x[0] <= 1981.0) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }

                                            else {
                                                if (x[1] <= 17.619999885559082) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    if (x[1] <= 17.639999389648438) {
                                                        if (x[0] <= 1546.5) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 1506.5) {
                                                            if (x[0] <= 1446.5) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }

                                                        else {
                                                            if (x[1] <= 17.729999542236328) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                if (x[0] <= 1554.5) {
                                                                    if (x[1] <= 17.75) {
                                                                        if (x[0] <= 1533.5) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }

                                        else {
                                            if (x[0] <= 1444.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                if (x[0] <= 2079.5) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1] <= 18.114999771118164) {
                                            if (x[0] <= 1978.5) {
                                                if (x[0] <= 1173.0) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    if (x[1] <= 17.84000015258789) {
                                                        if (x[0] <= 1525.0) {
                                                            if (x[0] <= 1466.0) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }

                                                        else {
                                                            if (x[1] <= 17.8149995803833) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 1563.5) {
                                                            if (x[1] <= 17.860000610351562) {
                                                                if (x[0] <= 1527.5) {
                                                                    if (x[0] <= 1486.0) {
                                                                        if (x[0] <= 1480.5) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[0] <= 2769.0) {
                                                    if (x[1] <= 18.010000228881836) {
                                                        if (x[1] <= 17.989999771118164) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            if (x[0] <= 2411.0) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                if (x[0] <= 2623.5) {
                                                                    if (x[0] <= 2540.5) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[0] <= 2628.5) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 2630.5) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }

                                                else {
                                                    votes[2] += 1;
                                                }
                                            }
                                        }

                                        else {
                                            if (x[0] <= 2617.5) {
                                                if (x[1] <= 19.989999771118164) {
                                                    if (x[1] <= 18.394999504089355) {
                                                        if (x[1] <= 18.170000076293945) {
                                                            if (x[1] <= 18.139999389648438) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 1946.0) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                if (x[1] <= 18.369999885559082) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 18.994999885559082) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            if (x[1] <= 19.005000114440918) {
                                                                if (x[0] <= 1140.5) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[1] <= 19.34000015258789) {
                                                                    if (x[0] <= 1919.0) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[1] <= 19.880000114440918) {
                                                                        if (x[0] <= 2100.5) {
                                                                            if (x[0] <= 1193.5) {
                                                                                if (x[0] <= 1036.0) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 2613.5) {
                                                                                if (x[1] <= 19.369999885559082) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                if (x[1] <= 19.449999809265137) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 19.920000076293945) {
                                                                            if (x[0] <= 1362.5) {
                                                                                if (x[0] <= 1117.0) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[1] <= 19.940000534057617) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                if (x[0] <= 1158.0) {
                                                                                    if (x[0] <= 917.0) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[1] += 1;
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[1] <= 20.114999771118164) {
                                                        if (x[1] <= 20.030000686645508) {
                                                            if (x[1] <= 20.010000228881836) {
                                                                if (x[0] <= 1751.5) {
                                                                    if (x[0] <= 1061.0) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1480.0) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1619.0) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1340.0) {
                                                                    if (x[0] <= 1124.5) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[0] <= 1590.5) {
                                                                        if (x[0] <= 1492.5) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[1] <= 20.06999969482422) {
                                                                if (x[1] <= 20.050000190734863) {
                                                                    if (x[0] <= 1313.0) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1556.5) {
                                                                            if (x[0] <= 1533.0) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[0] <= 1379.0) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1201.5) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    if (x[1] <= 20.09000015258789) {
                                                                        if (x[0] <= 1560.5) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1585.5) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1491.0) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1496.0) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                if (x[0] <= 1511.0) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    if (x[0] <= 1519.5) {
                                                                                        votes[2] += 1;
                                                                                    }

                                                                                    else {
                                                                                        if (x[0] <= 1586.0) {
                                                                                            if (x[0] <= 1563.5) {
                                                                                                if (x[0] <= 1546.0) {
                                                                                                    votes[1] += 1;
                                                                                                }

                                                                                                else {
                                                                                                    votes[1] += 1;
                                                                                                }
                                                                                            }

                                                                                            else {
                                                                                                votes[1] += 1;
                                                                                            }
                                                                                        }

                                                                                        else {
                                                                                            if (x[0] <= 1587.5) {
                                                                                                votes[1] += 1;
                                                                                            }

                                                                                            else {
                                                                                                votes[1] += 1;
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 20.15999984741211) {
                                                            if (x[0] <= 1292.0) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                if (x[1] <= 20.139999389648438) {
                                                                    if (x[0] <= 1585.0) {
                                                                        if (x[0] <= 1575.5) {
                                                                            if (x[0] <= 1491.5) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                if (x[0] <= 1505.0) {
                                                                                    votes[2] += 1;
                                                                                }

                                                                                else {
                                                                                    if (x[0] <= 1545.5) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[1] += 1;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[0] <= 1520.5) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1564.0) {
                                                                            if (x[0] <= 1560.0) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 1525.0) {
                                                                if (x[0] <= 1278.5) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    if (x[0] <= 1500.5) {
                                                                        if (x[0] <= 1493.0) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1583.5) {
                                                                    if (x[0] <= 1544.0) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[0] <= 1587.5) {
                                                                        if (x[0] <= 1585.5) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1586.5) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[1] <= 19.469999313354492) {
                                                    if (x[1] <= 18.979999542236328) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        if (x[0] <= 2643.5) {
                                                            if (x[0] <= 2618.5) {
                                                                if (x[1] <= 19.449999809265137) {
                                                                    if (x[1] <= 19.40499973297119) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 19.43000030517578) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 2638.0) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }
                                                }

                                                else {
                                                    votes[2] += 1;
                                                }
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[1] <= 24.010000228881836) {
                                        if (x[1] <= 20.90999984741211) {
                                            if (x[0] <= 1543.5) {
                                                if (x[1] <= 20.270000457763672) {
                                                    if (x[1] <= 20.244999885559082) {
                                                        if (x[1] <= 20.199999809265137) {
                                                            if (x[0] <= 1502.0) {
                                                                if (x[0] <= 1331.5) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    if (x[0] <= 1495.0) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            if (x[1] <= 20.219999313354492) {
                                                                if (x[0] <= 1331.5) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    if (x[0] <= 1518.5) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1522.0) {
                                                                    if (x[0] <= 1494.5) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1505.5) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 1504.5) {
                                                            if (x[0] <= 1499.5) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                if (x[0] <= 1503.5) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 1534.5) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[1] <= 20.5) {
                                                        if (x[0] <= 1501.5) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            if (x[1] <= 20.47000026702881) {
                                                                if (x[1] <= 20.369999885559082) {
                                                                    if (x[0] <= 1522.0) {
                                                                        if (x[1] <= 20.289999961853027) {
                                                                            if (x[0] <= 1503.5) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1529.5) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1521.0) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        votes[2] += 1;
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[0] <= 1587.5) {
                                                    if (x[0] <= 1554.5) {
                                                        if (x[1] <= 20.270000457763672) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 20.199999809265137) {
                                                            if (x[0] <= 1584.5) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[0] <= 1588.5) {
                                                        if (x[1] <= 20.3100004196167) {
                                                            if (x[1] <= 20.234999656677246) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 20.219999313354492) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }
                                                }
                                            }
                                        }

                                        else {
                                            if (x[1] <= 21.755000114440918) {
                                                if (x[1] <= 21.015000343322754) {
                                                    if (x[0] <= 1225.5) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        if (x[0] <= 1386.5) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[0] <= 1702.0) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        votes[2] += 1;
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[0] <= 1080.5) {
                                                    if (x[1] <= 22.570000648498535) {
                                                        if (x[1] <= 21.885000228881836) {
                                                            if (x[0] <= 868.0) {
                                                                if (x[0] <= 829.0) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 23.5) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[0] <= 3861.5) {
                                                        if (x[1] <= 23.469999313354492) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            if (x[0] <= 3651.5) {
                                                                if (x[1] <= 23.760000228881836) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    if (x[0] <= 1230.0) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 4084.5) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            if (x[1] <= 23.520000457763672) {
                                                                if (x[1] <= 23.489999771118164) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1] <= 24.81999969482422) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[2] += 1;
                                        }
                                    }
                                }
                            }
                        }

                        // tree #4
                        if (x[0] <= 301.5) {
                            if (x[0] <= 77.5) {
                                if (x[1] <= 21.09000015258789) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[1] <= 21.59000015258789) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[0] <= 262.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[0] <= 264.5) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }
                        }

                        else {
                            if (x[1] <= 17.059999465942383) {
                                if (x[1] <= 16.265000343322754) {
                                    if (x[0] <= 1185.5) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }

                                else {
                                    if (x[1] <= 16.994999885559082) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[1] <= 17.005000114440918) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            if (x[0] <= 1591.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[0] <= 1124.5) {
                                    if (x[0] <= 1118.5) {
                                        if (x[1] <= 22.570000648498535) {
                                            if (x[0] <= 717.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                if (x[0] <= 723.0) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    if (x[0] <= 1041.0) {
                                                        if (x[0] <= 850.5) {
                                                            if (x[0] <= 847.5) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 1042.5) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }
                                                }
                                            }
                                        }

                                        else {
                                            if (x[1] <= 23.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1] <= 21.175000190734863) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }

                                else {
                                    if (x[0] <= 3816.0) {
                                        if (x[0] <= 2649.5) {
                                            if (x[1] <= 20.244999885559082) {
                                                if (x[0] <= 1557.5) {
                                                    if (x[1] <= 18.449999809265137) {
                                                        if (x[0] <= 1533.5) {
                                                            if (x[0] <= 1433.5) {
                                                                if (x[0] <= 1264.0) {
                                                                    if (x[0] <= 1179.0) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[1] <= 17.824999809265137) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1484.0) {
                                                                    if (x[0] <= 1478.5) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1480.0) {
                                                                            if (x[1] <= 17.850000381469727) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[1] <= 17.770000457763672) {
                                                                        if (x[1] <= 17.639999389648438) {
                                                                            if (x[1] <= 17.589999198913574) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[1] <= 17.729999542236328) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                if (x[0] <= 1493.5) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    if (x[0] <= 1522.0) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[1] += 1;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1485.5) {
                                                                            if (x[1] <= 17.860000610351562) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[1] <= 17.789999961853027) {
                                                                if (x[1] <= 17.729999542236328) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    if (x[1] <= 17.75) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                if (x[1] <= 17.84000015258789) {
                                                                    if (x[1] <= 17.8149995803833) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[1] <= 17.90000057220459) {
                                                                        if (x[1] <= 17.860000610351562) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 19.989999771118164) {
                                                            if (x[1] <= 19.199999809265137) {
                                                                if (x[1] <= 18.9399995803833) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1203.0) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 1211.5) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                if (x[0] <= 1554.5) {
                                                                    if (x[0] <= 1494.5) {
                                                                        if (x[0] <= 1475.0) {
                                                                            if (x[1] <= 20.020000457763672) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[1] <= 20.030000686645508) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1502.5) {
                                                                            if (x[1] <= 20.114999771118164) {
                                                                                if (x[0] <= 1498.5) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    if (x[1] <= 20.09000015258789) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[2] += 1;
                                                                                    }
                                                                                }
                                                                            }

                                                                            else {
                                                                                if (x[0] <= 1498.5) {
                                                                                    if (x[1] <= 20.18000030517578) {
                                                                                        votes[2] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[2] += 1;
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    if (x[1] <= 20.170000076293945) {
                                                                                        votes[2] += 1;
                                                                                    }

                                                                                    else {
                                                                                        if (x[1] <= 20.199999809265137) {
                                                                                            votes[1] += 1;
                                                                                        }

                                                                                        else {
                                                                                            votes[1] += 1;
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1506.5) {
                                                                                if (x[0] <= 1503.5) {
                                                                                    if (x[1] <= 20.18000030517578) {
                                                                                        votes[2] += 1;
                                                                                    }

                                                                                    else {
                                                                                        if (x[1] <= 20.219999313354492) {
                                                                                            if (x[1] <= 20.199999809265137) {
                                                                                                votes[1] += 1;
                                                                                            }

                                                                                            else {
                                                                                                votes[1] += 1;
                                                                                            }
                                                                                        }

                                                                                        else {
                                                                                            votes[1] += 1;
                                                                                        }
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    if (x[0] <= 1504.5) {
                                                                                        if (x[1] <= 20.199999809265137) {
                                                                                            votes[1] += 1;
                                                                                        }

                                                                                        else {
                                                                                            votes[1] += 1;
                                                                                        }
                                                                                    }

                                                                                    else {
                                                                                        if (x[0] <= 1505.5) {
                                                                                            votes[1] += 1;
                                                                                        }

                                                                                        else {
                                                                                            if (x[1] <= 20.199999809265137) {
                                                                                                votes[1] += 1;
                                                                                            }

                                                                                            else {
                                                                                                votes[1] += 1;
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }

                                                                            else {
                                                                                if (x[1] <= 20.219999313354492) {
                                                                                    if (x[1] <= 20.114999771118164) {
                                                                                        if (x[1] <= 20.09000015258789) {
                                                                                            votes[1] += 1;
                                                                                        }

                                                                                        else {
                                                                                            if (x[0] <= 1519.0) {
                                                                                                votes[1] += 1;
                                                                                            }

                                                                                            else {
                                                                                                votes[1] += 1;
                                                                                            }
                                                                                        }
                                                                                    }

                                                                                    else {
                                                                                        if (x[0] <= 1530.5) {
                                                                                            if (x[0] <= 1517.5) {
                                                                                                if (x[1] <= 20.199999809265137) {
                                                                                                    if (x[1] <= 20.149999618530273) {
                                                                                                        votes[1] += 1;
                                                                                                    }

                                                                                                    else {
                                                                                                        votes[1] += 1;
                                                                                                    }
                                                                                                }

                                                                                                else {
                                                                                                    if (x[0] <= 1508.5) {
                                                                                                        votes[1] += 1;
                                                                                                    }

                                                                                                    else {
                                                                                                        votes[1] += 1;
                                                                                                    }
                                                                                                }
                                                                                            }

                                                                                            else {
                                                                                                votes[2] += 1;
                                                                                            }
                                                                                        }

                                                                                        else {
                                                                                            votes[1] += 1;
                                                                                        }
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    if (x[0] <= 1528.5) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[2] += 1;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[0] <= 1555.5) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 20.114999771118164) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[1] <= 19.449999809265137) {
                                                        if (x[0] <= 2538.0) {
                                                            if (x[1] <= 17.94499969482422) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                if (x[0] <= 1979.5) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    if (x[1] <= 18.020000457763672) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 18.920000076293945) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 2378.0) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[1] <= 19.34000015258789) {
                                                                if (x[1] <= 18.010000228881836) {
                                                                    if (x[0] <= 2625.5) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 17.989999771118164) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 2628.5) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[1] <= 18.994999885559082) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 2638.5) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[1] <= 19.100000381469727) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                if (x[1] <= 19.380000114440918) {
                                                                    if (x[1] <= 19.360000610351562) {
                                                                        if (x[0] <= 2616.0) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 2618.0) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[1] <= 19.40499973297119) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 19.43000030517578) {
                                                                            if (x[0] <= 2618.5) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 2614.5) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 20.18000030517578) {
                                                            if (x[1] <= 19.530000686645508) {
                                                                if (x[0] <= 2096.5) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1749.5) {
                                                                    if (x[1] <= 20.09000015258789) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 20.139999389648438) {
                                                                            if (x[0] <= 1585.5) {
                                                                                if (x[1] <= 20.114999771118164) {
                                                                                    if (x[0] <= 1583.5) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[2] += 1;
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    if (x[0] <= 1576.0) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[2] += 1;
                                                                                    }
                                                                                }
                                                                            }

                                                                            else {
                                                                                if (x[1] <= 20.114999771118164) {
                                                                                    if (x[0] <= 1587.5) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[1] += 1;
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[1] <= 20.15999984741211) {
                                                                                if (x[0] <= 1585.0) {
                                                                                    if (x[0] <= 1564.0) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[2] += 1;
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                if (x[0] <= 1583.5) {
                                                                                    votes[2] += 1;
                                                                                }

                                                                                else {
                                                                                    if (x[0] <= 1586.5) {
                                                                                        if (x[0] <= 1585.5) {
                                                                                            votes[1] += 1;
                                                                                        }

                                                                                        else {
                                                                                            votes[2] += 1;
                                                                                        }
                                                                                    }

                                                                                    else {
                                                                                        votes[1] += 1;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[1] <= 20.050000190734863) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 1589.5) {
                                                                if (x[1] <= 20.199999809265137) {
                                                                    if (x[0] <= 1586.0) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[0] <= 1199.0) {
                                                    if (x[0] <= 1171.0) {
                                                        if (x[1] <= 21.625) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 21.085000038146973) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[0] <= 1613.0) {
                                                        if (x[0] <= 1573.5) {
                                                            if (x[1] <= 20.270000457763672) {
                                                                if (x[0] <= 1504.5) {
                                                                    if (x[0] <= 1500.0) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1503.5) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[0] <= 1506.0) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1546.0) {
                                                                            if (x[0] <= 1534.5) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1528.0) {
                                                                    if (x[0] <= 1522.5) {
                                                                        if (x[0] <= 1501.5) {
                                                                            if (x[0] <= 1263.0) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                if (x[0] <= 1268.5) {
                                                                                    votes[2] += 1;
                                                                                }

                                                                                else {
                                                                                    if (x[1] <= 21.015000343322754) {
                                                                                        votes[2] += 1;
                                                                                    }

                                                                                    else {
                                                                                        if (x[0] <= 1301.5) {
                                                                                            votes[1] += 1;
                                                                                        }

                                                                                        else {
                                                                                            if (x[0] <= 1453.0) {
                                                                                                votes[2] += 1;
                                                                                            }

                                                                                            else {
                                                                                                if (x[1] <= 21.519999504089355) {
                                                                                                    votes[1] += 1;
                                                                                                }

                                                                                                else {
                                                                                                    votes[2] += 1;
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1502.5) {
                                                                                if (x[1] <= 20.3100004196167) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                if (x[1] <= 20.94499969482422) {
                                                                                    if (x[1] <= 20.460000038146973) {
                                                                                        votes[2] += 1;
                                                                                    }

                                                                                    else {
                                                                                        if (x[1] <= 20.515000343322754) {
                                                                                            votes[2] += 1;
                                                                                        }

                                                                                        else {
                                                                                            votes[2] += 1;
                                                                                        }
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    if (x[1] <= 21.90499973297119) {
                                                                                        votes[2] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[2] += 1;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1524.0) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[1] <= 20.8700008392334) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[1] <= 20.90999984741211) {
                                                                        if (x[1] <= 20.369999885559082) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1553.5) {
                                                                                if (x[1] <= 20.394999504089355) {
                                                                                    if (x[0] <= 1544.0) {
                                                                                        votes[2] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[2] += 1;
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1560.5) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[1] <= 20.739999771118164) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                if (x[0] <= 1576.0) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    if (x[1] <= 21.515000343322754) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        votes[2] += 1;
                                                    }
                                                }
                                            }
                                        }

                                        else {
                                            if (x[1] <= 18.854999542236328) {
                                                if (x[1] <= 17.869999885559082) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    if (x[1] <= 18.050000190734863) {
                                                        votes[2] += 1;
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[1] <= 24.010000228881836) {
                                                    if (x[0] <= 3477.0) {
                                                        if (x[0] <= 2991.5) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            if (x[1] <= 23.454999923706055) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 3742.0) {
                                                            if (x[1] <= 23.989999771118164) {
                                                                if (x[0] <= 3692.0) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[1] <= 24.774999618530273) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        votes[2] += 1;
                                                    }
                                                }
                                            }
                                        }
                                    }

                                    else {
                                        if (x[0] <= 3904.0) {
                                            if (x[1] <= 23.024999618530273) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                if (x[1] <= 23.5) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }

                                        else {
                                            if (x[1] <= 23.5) {
                                                if (x[1] <= 23.469999313354492) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #5
                        if (x[1] <= 17.059999465942383) {
                            if (x[1] <= 16.265000343322754) {
                                if (x[1] <= 13.5) {
                                    if (x[0] <= 314.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[1] <= 9.5) {
                                            if (x[1] <= 8.5) {
                                                if (x[0] <= 1533.0) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    votes[2] += 1;
                                                }
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }

                                        else {
                                            if (x[1] <= 12.5) {
                                                if (x[0] <= 863.5) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }

                                            else {
                                                if (x[0] <= 1177.0) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    votes[2] += 1;
                                                }
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[0] <= 306.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[1] <= 14.5) {
                                            if (x[0] <= 1549.0) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }

                                        else {
                                            if (x[1] <= 15.96500015258789) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                if (x[0] <= 1536.5) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    votes[2] += 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[0] <= 2071.5) {
                                    if (x[1] <= 16.994999885559082) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[1] <= 17.005000114440918) {
                                            if (x[0] <= 320.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }
                                }

                                else {
                                    votes[2] += 1;
                                }
                            }
                        }

                        else {
                            if (x[0] <= 300.5) {
                                if (x[0] <= 2.5) {
                                    if (x[1] <= 21.015000343322754) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[1] <= 21.59000015258789) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }
                                }

                                else {
                                    if (x[0] <= 77.5) {
                                        if (x[1] <= 21.09000015258789) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[1] <= 22.5) {
                                                if (x[0] <= 54.0) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    votes[0] += 1;
                                                }
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[1] <= 20.199999809265137) {
                                    if (x[0] <= 1557.5) {
                                        if (x[1] <= 18.449999809265137) {
                                            if (x[0] <= 1531.5) {
                                                if (x[0] <= 1083.0) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    if (x[0] <= 1433.5) {
                                                        if (x[0] <= 1345.0) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            if (x[0] <= 1379.5) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                if (x[1] <= 17.760000228881836) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 17.789999961853027) {
                                                            if (x[1] <= 17.609999656677246) {
                                                                if (x[0] <= 1515.5) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1510.0) {
                                                                    if (x[1] <= 17.760000228881836) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[0] <= 1524.0) {
                                                                        if (x[1] <= 17.684999465942383) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 1487.5) {
                                                                if (x[1] <= 17.860000610351562) {
                                                                    if (x[0] <= 1480.5) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1486.0) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[1] <= 17.84000015258789) {
                                                    if (x[1] <= 17.770000457763672) {
                                                        if (x[0] <= 1534.5) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            if (x[1] <= 17.729999542236328) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                if (x[1] <= 17.75) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 17.8149995803833) {
                                                            if (x[1] <= 17.789999961853027) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[0] <= 1534.5) {
                                                        votes[2] += 1;
                                                    }

                                                    else {
                                                        votes[2] += 1;
                                                    }
                                                }
                                            }
                                        }

                                        else {
                                            if (x[0] <= 1328.5) {
                                                if (x[1] <= 20.010000228881836) {
                                                    if (x[1] <= 19.835000038146973) {
                                                        if (x[1] <= 19.229999542236328) {
                                                            if (x[0] <= 1023.5) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 19.880000114440918) {
                                                            if (x[1] <= 19.860000610351562) {
                                                                if (x[0] <= 1121.0) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 918.5) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 1066.5) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                if (x[1] <= 19.975000381469727) {
                                                                    if (x[1] <= 19.920000076293945) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[0] <= 1211.5) {
                                                        if (x[1] <= 20.030000686645508) {
                                                            if (x[0] <= 1152.5) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 1250.5) {
                                                            if (x[1] <= 20.0600004196167) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[1] <= 20.06999969482422) {
                                                    if (x[1] <= 19.34000015258789) {
                                                        if (x[0] <= 1479.5) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 19.975000381469727) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            if (x[1] <= 20.010000228881836) {
                                                                if (x[0] <= 1489.5) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1555.5) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[0] <= 1544.0) {
                                                        if (x[0] <= 1494.5) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            if (x[1] <= 20.18000030517578) {
                                                                if (x[0] <= 1496.0) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    if (x[0] <= 1501.5) {
                                                                        if (x[0] <= 1498.5) {
                                                                            if (x[1] <= 20.114999771118164) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 20.09000015258789) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1508.0) {
                                                                                if (x[1] <= 20.15999984741211) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    if (x[0] <= 1504.5) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[1] += 1;
                                                                                    }
                                                                                }
                                                                            }

                                                                            else {
                                                                                if (x[1] <= 20.149999618530273) {
                                                                                    if (x[0] <= 1517.5) {
                                                                                        votes[2] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[1] += 1;
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        votes[2] += 1;
                                                    }
                                                }
                                            }
                                        }
                                    }

                                    else {
                                        if (x[0] <= 2617.5) {
                                            if (x[0] <= 1581.5) {
                                                if (x[0] <= 1567.5) {
                                                    if (x[0] <= 1561.5) {
                                                        if (x[1] <= 20.125) {
                                                            if (x[0] <= 1558.5) {
                                                                if (x[1] <= 18.84000015258789) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 20.079999923706055) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            if (x[1] <= 20.15999984741211) {
                                                                if (x[0] <= 1562.5) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1564.0) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[0] <= 1571.5) {
                                                        if (x[0] <= 1570.5) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            if (x[1] <= 17.649999618530273) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[0] <= 1584.5) {
                                                    if (x[1] <= 20.06999969482422) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        if (x[0] <= 1583.5) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            if (x[1] <= 20.15999984741211) {
                                                                if (x[1] <= 20.114999771118164) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    if (x[1] <= 20.139999389648438) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[1] <= 19.34000015258789) {
                                                        if (x[1] <= 17.989999771118164) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            if (x[1] <= 18.020000457763672) {
                                                                if (x[0] <= 2349.5) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1921.5) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    if (x[1] <= 19.005000114440918) {
                                                                        if (x[0] <= 2530.5) {
                                                                            if (x[1] <= 18.920000076293945) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 19.975000381469727) {
                                                            if (x[1] <= 19.619999885559082) {
                                                                if (x[1] <= 19.449999809265137) {
                                                                    if (x[0] <= 2612.5) {
                                                                        if (x[1] <= 19.360000610351562) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 2105.0) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 1599.5) {
                                                                if (x[0] <= 1587.5) {
                                                                    if (x[0] <= 1586.5) {
                                                                        if (x[0] <= 1585.5) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 20.09000015258789) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[1] <= 20.18000030517578) {
                                                                                if (x[1] <= 20.114999771118164) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    if (x[1] <= 20.15999984741211) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[1] += 1;
                                                                                    }
                                                                                }
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 2510.0) {
                                                                    if (x[0] <= 2415.0) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 2486.5) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }

                                        else {
                                            if (x[1] <= 19.449999809265137) {
                                                if (x[1] <= 18.010000228881836) {
                                                    if (x[0] <= 2756.0) {
                                                        if (x[1] <= 17.989999771118164) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            if (x[0] <= 2630.5) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 17.664999961853027) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[1] <= 18.979999542236328) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        if (x[0] <= 2643.5) {
                                                            if (x[0] <= 2638.0) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[1] <= 19.469999313354492) {
                                                    if (x[0] <= 2618.5) {
                                                        votes[2] += 1;
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }

                                                else {
                                                    votes[2] += 1;
                                                }
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[1] <= 23.469999313354492) {
                                        if (x[0] <= 1165.5) {
                                            if (x[1] <= 20.609999656677246) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                if (x[1] <= 21.829999923706055) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    if (x[1] <= 21.885000228881836) {
                                                        if (x[1] <= 21.860000610351562) {
                                                            if (x[0] <= 992.0) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 849.5) {
                                                                if (x[0] <= 783.0) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }
                                            }
                                        }

                                        else {
                                            if (x[1] <= 20.270000457763672) {
                                                if (x[1] <= 20.244999885559082) {
                                                    if (x[0] <= 1546.0) {
                                                        if (x[1] <= 20.219999313354492) {
                                                            if (x[0] <= 1347.0) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                if (x[0] <= 1511.5) {
                                                                    if (x[0] <= 1501.5) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1503.5) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1506.5) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[0] <= 1532.5) {
                                                                        if (x[0] <= 1517.5) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 1503.5) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                if (x[0] <= 1528.0) {
                                                                    if (x[0] <= 1504.5) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1508.5) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 1587.5) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[0] <= 1507.0) {
                                                        if (x[0] <= 1501.5) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            if (x[0] <= 1504.5) {
                                                                if (x[0] <= 1503.5) {
                                                                    if (x[0] <= 1502.5) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 1555.5) {
                                                            if (x[0] <= 1531.0) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                if (x[0] <= 1544.0) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[0] <= 1199.0) {
                                                    if (x[0] <= 1181.5) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        if (x[1] <= 20.655000686645508) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[1] <= 21.460000038146973) {
                                                        if (x[1] <= 21.015000343322754) {
                                                            if (x[0] <= 1501.5) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                if (x[1] <= 20.289999961853027) {
                                                                    if (x[0] <= 1506.0) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1587.5) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[0] <= 1524.5) {
                                                                        if (x[0] <= 1521.5) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 20.394999504089355) {
                                                                            if (x[1] <= 20.369999885559082) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                if (x[0] <= 1553.5) {
                                                                                    votes[2] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 23.350000381469727) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            if (x[1] <= 23.380000114440918) {
                                                                if (x[0] <= 2293.0) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1] <= 24.81999969482422) {
                                            if (x[0] <= 2967.0) {
                                                if (x[0] <= 957.0) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    if (x[0] <= 2807.5) {
                                                        votes[2] += 1;
                                                    }

                                                    else {
                                                        if (x[0] <= 2829.5) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[1] <= 23.489999771118164) {
                                                    if (x[0] <= 3991.5) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }

                                                else {
                                                    if (x[1] <= 24.010000228881836) {
                                                        if (x[1] <= 23.989999771118164) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }
                                            }
                                        }

                                        else {
                                            votes[2] += 1;
                                        }
                                    }
                                }
                            }
                        }

                        // tree #6
                        if (x[1] <= 17.079999923706055) {
                            if (x[0] <= 1676.5) {
                                if (x[1] <= 16.265000343322754) {
                                    if (x[1] <= 8.5) {
                                        if (x[0] <= 374.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }

                                    else {
                                        if (x[1] <= 13.5) {
                                            if (x[1] <= 9.5) {
                                                if (x[0] <= 88.0) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    votes[0] += 1;
                                                }
                                            }

                                            else {
                                                if (x[0] <= 376.5) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    if (x[1] <= 11.0) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        if (x[1] <= 12.5) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            if (x[0] <= 1183.5) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }

                                        else {
                                            if (x[0] <= 309.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[0] <= 858.5) {
                                        if (x[0] <= 320.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[0] <= 1799.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[0] <= 2408.0) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        if (x[0] <= 2513.0) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            if (x[0] <= 2586.5) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        else {
                            if (x[0] <= 299.5) {
                                if (x[0] <= 1.5) {
                                    if (x[1] <= 21.015000343322754) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[1] <= 21.59000015258789) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }
                                }

                                else {
                                    if (x[1] <= 21.199999809265137) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[0] <= 207.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[0] <= 268.0) {
                                                if (x[0] <= 256.5) {
                                                    if (x[0] <= 247.0) {
                                                        votes[0] += 1;
                                                    }

                                                    else {
                                                        votes[0] += 1;
                                                    }
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[0] <= 1114.5) {
                                    if (x[1] <= 21.860000610351562) {
                                        if (x[1] <= 20.675000190734863) {
                                            if (x[1] <= 20.114999771118164) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }

                                    else {
                                        if (x[0] <= 848.5) {
                                            if (x[0] <= 796.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }

                                else {
                                    if (x[1] <= 20.199999809265137) {
                                        if (x[0] <= 1534.5) {
                                            if (x[1] <= 18.4399995803833) {
                                                if (x[1] <= 17.789999961853027) {
                                                    if (x[0] <= 1431.0) {
                                                        if (x[1] <= 17.770000457763672) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 1486.5) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            if (x[1] <= 17.639999389648438) {
                                                                if (x[1] <= 17.589999198913574) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1522.0) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    if (x[0] <= 1531.5) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[0] <= 1176.5) {
                                                        votes[2] += 1;
                                                    }

                                                    else {
                                                        if (x[0] <= 1376.5) {
                                                            if (x[0] <= 1259.5) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 1487.5) {
                                                                if (x[0] <= 1484.0) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    if (x[1] <= 17.860000610351562) {
                                                                        if (x[0] <= 1486.5) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[0] <= 1208.0) {
                                                    if (x[0] <= 1172.0) {
                                                        votes[2] += 1;
                                                    }

                                                    else {
                                                        if (x[1] <= 20.030000686645508) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[1] <= 19.989999771118164) {
                                                        if (x[0] <= 1241.0) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            if (x[0] <= 1387.0) {
                                                                if (x[1] <= 19.579999923706055) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 1260.0) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            if (x[0] <= 1494.5) {
                                                                if (x[0] <= 1294.5) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    if (x[1] <= 20.030000686645508) {
                                                                        if (x[0] <= 1490.5) {
                                                                            if (x[1] <= 20.010000228881836) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1496.0) {
                                                                    if (x[1] <= 20.104999542236328) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[0] <= 1502.0) {
                                                                        if (x[0] <= 1500.0) {
                                                                            if (x[1] <= 20.114999771118164) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                if (x[0] <= 1498.5) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1508.5) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1518.5) {
                                                                                if (x[1] <= 20.114999771118164) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }

                                        else {
                                            if (x[1] <= 19.449999809265137) {
                                                if (x[1] <= 17.770000457763672) {
                                                    if (x[0] <= 1546.5) {
                                                        if (x[1] <= 17.729999542236328) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            if (x[1] <= 17.75) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }

                                                else {
                                                    if (x[0] <= 2021.5) {
                                                        if (x[1] <= 17.860000610351562) {
                                                            if (x[1] <= 17.789999961853027) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                if (x[1] <= 17.8149995803833) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    if (x[1] <= 17.84000015258789) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[1] <= 18.449999809265137) {
                                                                if (x[1] <= 17.920000076293945) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    if (x[1] <= 17.989999771118164) {
                                                                        if (x[1] <= 17.96500015258789) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1546.5) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 18.039999961853027) {
                                                                            if (x[0] <= 1545.5) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                if (x[1] <= 18.854999542236328) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 18.010000228881836) {
                                                            if (x[0] <= 2641.5) {
                                                                if (x[1] <= 17.989999771118164) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    if (x[0] <= 2583.5) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 2628.5) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 2646.0) {
                                                                if (x[1] <= 19.34000015258789) {
                                                                    if (x[0] <= 2638.5) {
                                                                        if (x[0] <= 2530.5) {
                                                                            if (x[1] <= 18.789999961853027) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                if (x[1] <= 19.1899995803833) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 18.979999542236328) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[1] <= 19.360000610351562) {
                                                                        if (x[0] <= 2614.5) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 19.43000030517578) {
                                                                            if (x[1] <= 19.40499973297119) {
                                                                                if (x[0] <= 2614.5) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 2616.0) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 2764.0) {
                                                                    if (x[0] <= 2678.5) {
                                                                        if (x[0] <= 2669.5) {
                                                                            if (x[0] <= 2656.5) {
                                                                                if (x[0] <= 2649.5) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 18.854999542236328) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[1] <= 19.6850004196167) {
                                                    if (x[1] <= 19.639999389648438) {
                                                        if (x[1] <= 19.55500030517578) {
                                                            if (x[1] <= 19.469999313354492) {
                                                                if (x[0] <= 2618.5) {
                                                                    if (x[0] <= 2617.5) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[1] <= 19.489999771118164) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    if (x[0] <= 2096.5) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 2098.5) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 19.65999984741211) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            if (x[0] <= 2102.5) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[1] <= 20.139999389648438) {
                                                        if (x[0] <= 1776.0) {
                                                            if (x[0] <= 1556.5) {
                                                                if (x[1] <= 19.9950008392334) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    if (x[0] <= 1544.0) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1555.5) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                if (x[1] <= 20.06999969482422) {
                                                                    if (x[1] <= 19.899999618530273) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 19.920000076293945) {
                                                                            if (x[0] <= 1586.0) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[1] <= 20.010000228881836) {
                                                                                if (x[0] <= 1620.5) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[1] <= 20.09000015258789) {
                                                                        if (x[0] <= 1585.5) {
                                                                            if (x[0] <= 1572.0) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 20.114999771118164) {
                                                                            if (x[0] <= 1586.0) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1585.5) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 1585.5) {
                                                            if (x[0] <= 1544.5) {
                                                                if (x[1] <= 20.18000030517578) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1584.5) {
                                                                    if (x[0] <= 1561.5) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1562.5) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[1] <= 20.15999984741211) {
                                                                                if (x[0] <= 1573.0) {
                                                                                    votes[2] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[1] <= 20.18000030517578) {
                                                                if (x[0] <= 1587.5) {
                                                                    if (x[1] <= 20.15999984741211) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1586.5) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1588.5) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1] <= 23.510000228881836) {
                                            if (x[0] <= 1553.5) {
                                                if (x[0] <= 1487.5) {
                                                    if (x[1] <= 20.925000190734863) {
                                                        votes[2] += 1;
                                                    }

                                                    else {
                                                        if (x[0] <= 1459.0) {
                                                            if (x[1] <= 21.710000038146973) {
                                                                if (x[0] <= 1233.0) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    if (x[0] <= 1343.5) {
                                                                        if (x[0] <= 1281.0) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[0] <= 1507.5) {
                                                        if (x[1] <= 20.270000457763672) {
                                                            if (x[0] <= 1506.5) {
                                                                if (x[1] <= 20.219999313354492) {
                                                                    if (x[0] <= 1502.5) {
                                                                        if (x[0] <= 1496.0) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[1] <= 20.244999885559082) {
                                                                        if (x[0] <= 1503.5) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1504.5) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1502.5) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1504.5) {
                                                                                if (x[0] <= 1503.5) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }

                                                        else {
                                                            if (x[1] <= 20.289999961853027) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                if (x[1] <= 21.019999504089355) {
                                                                    if (x[0] <= 1502.5) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 20.515000343322754) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[0] <= 1499.5) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 1534.5) {
                                                            if (x[1] <= 20.244999885559082) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                if (x[0] <= 1522.5) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    if (x[0] <= 1524.0) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 20.8700008392334) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[1] <= 20.219999313354492) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                if (x[0] <= 1544.0) {
                                                                    if (x[1] <= 20.270000457763672) {
                                                                        if (x[1] <= 20.244999885559082) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[1] <= 20.339999198913574) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 20.489999771118164) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[1] <= 23.469999313354492) {
                                                    if (x[1] <= 23.399999618530273) {
                                                        if (x[1] <= 21.449999809265137) {
                                                            if (x[0] <= 1572.5) {
                                                                if (x[1] <= 20.630000114440918) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1577.5) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    if (x[0] <= 1638.0) {
                                                                        if (x[1] <= 20.424999237060547) {
                                                                            if (x[0] <= 1587.5) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                if (x[0] <= 1588.5) {
                                                                                    if (x[1] <= 20.3100004196167) {
                                                                                        if (x[1] <= 20.270000457763672) {
                                                                                            votes[2] += 1;
                                                                                        }

                                                                                        else {
                                                                                            votes[1] += 1;
                                                                                        }
                                                                                    }

                                                                                    else {
                                                                                        votes[2] += 1;
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 3844.5) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 23.434999465942383) {
                                                            if (x[0] <= 3068.5) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[0] <= 2990.0) {
                                                        votes[2] += 1;
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }
                                            }
                                        }

                                        else {
                                            if (x[1] <= 24.81999969482422) {
                                                if (x[1] <= 24.010000228881836) {
                                                    if (x[1] <= 23.989999771118164) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        if (x[0] <= 3312.0) {
                                                            if (x[0] <= 1281.5) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #7
                        if (x[0] <= 301.0) {
                            if (x[0] <= 13.5) {
                                if (x[0] <= 9.5) {
                                    if (x[1] <= 21.015000343322754) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[1] <= 21.59000015258789) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }

                            else {
                                if (x[1] <= 21.09000015258789) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[0] <= 257.0) {
                                        if (x[0] <= 200.0) {
                                            if (x[0] <= 77.5) {
                                                if (x[0] <= 76.5) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    votes[0] += 1;
                                                }
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }
                        }

                        else {
                            if (x[0] <= 1114.5) {
                                if (x[1] <= 20.675000190734863) {
                                    if (x[1] <= 20.039999961853027) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                if (x[1] <= 17.079999923706055) {
                                    if (x[1] <= 16.265000343322754) {
                                        if (x[0] <= 1240.0) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            votes[2] += 1;
                                        }
                                    }

                                    else {
                                        if (x[1] <= 16.994999885559082) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[1] <= 17.005000114440918) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[1] <= 20.219999313354492) {
                                        if (x[1] <= 17.770000457763672) {
                                            if (x[1] <= 17.619999885559082) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                if (x[1] <= 17.75) {
                                                    if (x[1] <= 17.729999542236328) {
                                                        if (x[1] <= 17.710000038146973) {
                                                            if (x[1] <= 17.639999389648438) {
                                                                if (x[0] <= 1566.0) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1511.0) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 1552.0) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 1509.5) {
                                                            if (x[0] <= 1431.5) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 1551.5) {
                                                                if (x[0] <= 1534.5) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[0] <= 1502.5) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }
                                            }
                                        }

                                        else {
                                            if (x[0] <= 1557.5) {
                                                if (x[1] <= 18.449999809265137) {
                                                    if (x[0] <= 1534.5) {
                                                        if (x[1] <= 17.789999961853027) {
                                                            if (x[0] <= 1272.0) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                if (x[0] <= 1479.0) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 1183.0) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                if (x[0] <= 1487.5) {
                                                                    if (x[1] <= 17.860000610351562) {
                                                                        if (x[0] <= 1486.5) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 1545.5) {
                                                            if (x[1] <= 17.84000015258789) {
                                                                if (x[1] <= 17.8149995803833) {
                                                                    if (x[1] <= 17.789999961853027) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[1] <= 18.050000190734863) {
                                                                    if (x[1] <= 18.010000228881836) {
                                                                        if (x[1] <= 17.90000057220459) {
                                                                            if (x[1] <= 17.860000610351562) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[0] <= 1208.0) {
                                                        if (x[0] <= 1172.0) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            if (x[0] <= 1174.5) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 20.114999771118164) {
                                                            if (x[1] <= 19.34000015258789) {
                                                                if (x[1] <= 18.9399995803833) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[1] <= 19.989999771118164) {
                                                                    if (x[1] <= 19.920000076293945) {
                                                                        if (x[0] <= 1239.0) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[0] <= 1294.5) {
                                                                        if (x[1] <= 20.0600004196167) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1554.5) {
                                                                            if (x[1] <= 20.010000228881836) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                if (x[0] <= 1500.0) {
                                                                                    if (x[1] <= 20.09000015258789) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        if (x[0] <= 1494.5) {
                                                                                            votes[1] += 1;
                                                                                        }

                                                                                        else {
                                                                                            if (x[0] <= 1496.0) {
                                                                                                votes[1] += 1;
                                                                                            }

                                                                                            else {
                                                                                                votes[1] += 1;
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[1] <= 20.18000030517578) {
                                                                if (x[0] <= 1544.0) {
                                                                    if (x[0] <= 1492.0) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1496.5) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[1] <= 20.139999389648438) {
                                                                                if (x[0] <= 1509.5) {
                                                                                    votes[2] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                if (x[1] <= 20.15999984741211) {
                                                                                    if (x[0] <= 1520.5) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[1] += 1;
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    if (x[0] <= 1522.0) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[1] += 1;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1545.5) {
                                                                    if (x[1] <= 20.199999809265137) {
                                                                        if (x[0] <= 1502.0) {
                                                                            if (x[0] <= 1494.0) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1511.5) {
                                                                            if (x[0] <= 1502.5) {
                                                                                if (x[0] <= 1499.0) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1532.5) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[1] <= 19.449999809265137) {
                                                    if (x[1] <= 18.030000686645508) {
                                                        if (x[0] <= 2641.5) {
                                                            if (x[1] <= 17.989999771118164) {
                                                                if (x[0] <= 1826.0) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[1] <= 18.010000228881836) {
                                                                    if (x[0] <= 2583.5) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 2625.5) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 2628.5) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[0] <= 2626.5) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 18.994999885559082) {
                                                            if (x[1] <= 18.394999504089355) {
                                                                if (x[1] <= 18.369999885559082) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    if (x[0] <= 2630.0) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 2645.0) {
                                                                if (x[1] <= 19.005000114440918) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    if (x[1] <= 19.34000015258789) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 19.360000610351562) {
                                                                            if (x[0] <= 2612.5) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 2612.0) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[0] <= 1765.0) {
                                                        if (x[0] <= 1582.5) {
                                                            if (x[0] <= 1558.5) {
                                                                if (x[1] <= 20.114999771118164) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[1] <= 20.114999771118164) {
                                                                    if (x[0] <= 1560.5) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 20.06999969482422) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[1] <= 20.15999984741211) {
                                                                        if (x[1] <= 20.139999389648438) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1561.5) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1562.5) {
                                                                                if (x[1] <= 20.199999809265137) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 1587.5) {
                                                                if (x[0] <= 1584.5) {
                                                                    if (x[0] <= 1583.5) {
                                                                        if (x[1] <= 20.039999961853027) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 20.0600004196167) {
                                                                            if (x[1] <= 19.899999618530273) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                if (x[1] <= 19.920000076293945) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[1] <= 20.18000030517578) {
                                                                                if (x[1] <= 20.139999389648438) {
                                                                                    votes[2] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[1] <= 20.18000030517578) {
                                                                        if (x[0] <= 1586.5) {
                                                                            if (x[1] <= 20.15999984741211) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                if (x[0] <= 1585.5) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[1] <= 20.09000015258789) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                if (x[1] <= 20.114999771118164) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1588.5) {
                                                                    if (x[1] <= 20.18000030517578) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 20.114999771118164) {
                                                            if (x[1] <= 19.469999313354492) {
                                                                if (x[0] <= 2616.5) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }

                                    else {
                                        if (x[0] <= 3487.5) {
                                            if (x[0] <= 1196.5) {
                                                if (x[1] <= 20.625) {
                                                    votes[2] += 1;
                                                }

                                                else {
                                                    if (x[1] <= 21.710000038146973) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        if (x[1] <= 22.899999618530273) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[1] <= 20.270000457763672) {
                                                    if (x[0] <= 1504.5) {
                                                        if (x[1] <= 20.244999885559082) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            if (x[0] <= 1502.5) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                if (x[0] <= 1503.5) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 1555.5) {
                                                            if (x[1] <= 20.244999885559082) {
                                                                if (x[0] <= 1509.0) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    if (x[0] <= 1528.0) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1544.0) {
                                                                    if (x[0] <= 1534.5) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[0] <= 2991.5) {
                                                        if (x[0] <= 1503.5) {
                                                            if (x[0] <= 1501.5) {
                                                                if (x[1] <= 20.925000190734863) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    if (x[0] <= 1435.5) {
                                                                        if (x[0] <= 1223.5) {
                                                                            if (x[1] <= 21.5600004196167) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1385.0) {
                                                                                if (x[0] <= 1359.0) {
                                                                                    if (x[0] <= 1301.5) {
                                                                                        if (x[1] <= 21.625) {
                                                                                            votes[1] += 1;
                                                                                        }

                                                                                        else {
                                                                                            votes[2] += 1;
                                                                                        }
                                                                                    }

                                                                                    else {
                                                                                        votes[2] += 1;
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 21.59000015258789) {
                                                                            if (x[0] <= 1481.0) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                if (x[1] <= 20.515000343322754) {
                                                                    if (x[1] <= 20.350000381469727) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 1628.0) {
                                                                if (x[1] <= 21.03499984741211) {
                                                                    if (x[1] <= 20.289999961853027) {
                                                                        if (x[0] <= 1587.5) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 20.394999504089355) {
                                                                            if (x[1] <= 20.369999885559082) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                if (x[0] <= 1553.5) {
                                                                                    if (x[0] <= 1544.0) {
                                                                                        votes[2] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[2] += 1;
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[1] <= 21.505000114440918) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 2807.5) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    if (x[0] <= 2812.0) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 3337.5) {
                                                            if (x[1] <= 23.454999923706055) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            if (x[1] <= 23.295000076293945) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }

                                        else {
                                            if (x[1] <= 23.44499969482422) {
                                                if (x[1] <= 22.980000495910645) {
                                                    votes[2] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }

                                            else {
                                                if (x[1] <= 23.5) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    if (x[0] <= 3648.0) {
                                                        if (x[1] <= 24.27500057220459) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #8
                        if (x[0] <= 300.0) {
                            if (x[1] <= 21.015000343322754) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[0] <= 2.5) {
                                    if (x[1] <= 21.59000015258789) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }

                                else {
                                    if (x[1] <= 22.5) {
                                        if (x[0] <= 79.5) {
                                            if (x[0] <= 68.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }
                        }

                        else {
                            if (x[1] <= 17.059999465942383) {
                                if (x[0] <= 1153.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[0] <= 1842.0) {
                                        if (x[1] <= 14.765000343322754) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            if (x[0] <= 1676.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                if (x[0] <= 1692.5) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    votes[0] += 1;
                                                }
                                            }
                                        }
                                    }

                                    else {
                                        if (x[0] <= 2408.0) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            if (x[1] <= 15.46500015258789) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                if (x[0] <= 2628.5) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    votes[2] += 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[0] <= 1114.0) {
                                    if (x[1] <= 22.570000648498535) {
                                        if (x[1] <= 20.675000190734863) {
                                            if (x[0] <= 953.5) {
                                                if (x[0] <= 714.0) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    if (x[0] <= 744.5) {
                                                        votes[2] += 1;
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[0] <= 1073.0) {
                                                    if (x[0] <= 989.5) {
                                                        votes[2] += 1;
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }

                                        else {
                                            if (x[1] <= 21.860000610351562) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                if (x[1] <= 21.885000228881836) {
                                                    if (x[0] <= 791.0) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1] <= 23.5) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }

                                else {
                                    if (x[0] <= 3838.0) {
                                        if (x[1] <= 20.244999885559082) {
                                            if (x[0] <= 1486.0) {
                                                if (x[1] <= 19.295000076293945) {
                                                    if (x[1] <= 17.770000457763672) {
                                                        if (x[0] <= 1446.5) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 17.8149995803833) {
                                                            if (x[1] <= 17.789999961853027) {
                                                                if (x[0] <= 1373.0) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1410.5) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[0] <= 1207.5) {
                                                        if (x[1] <= 19.975000381469727) {
                                                            if (x[0] <= 1147.0) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 1291.0) {
                                                            if (x[1] <= 19.96500015258789) {
                                                                if (x[0] <= 1237.0) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[1] <= 20.070000648498535) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[0] <= 1567.5) {
                                                    if (x[1] <= 18.449999809265137) {
                                                        if (x[0] <= 1534.5) {
                                                            if (x[0] <= 1526.5) {
                                                                if (x[1] <= 17.77999973297119) {
                                                                    if (x[0] <= 1499.5) {
                                                                        if (x[1] <= 17.385000228881836) {
                                                                            votes[0] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1519.0) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[1] <= 17.815000534057617) {
                                                                    if (x[0] <= 1530.5) {
                                                                        if (x[0] <= 1529.5) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 1560.0) {
                                                                if (x[1] <= 17.84000015258789) {
                                                                    if (x[1] <= 17.789999961853027) {
                                                                        if (x[1] <= 17.729999542236328) {
                                                                            if (x[1] <= 17.710000038146973) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[1] <= 17.75) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 17.8149995803833) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[1] <= 17.910000801086426) {
                                                                        if (x[1] <= 17.860000610351562) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1546.0) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1545.5) {
                                                                            if (x[1] <= 18.039999961853027) {
                                                                                if (x[1] <= 18.010000228881836) {
                                                                                    votes[2] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 20.06999969482422) {
                                                            if (x[1] <= 20.010000228881836) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                if (x[0] <= 1491.0) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    if (x[1] <= 20.030000686645508) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 20.050000190734863) {
                                                                            if (x[0] <= 1556.5) {
                                                                                if (x[0] <= 1533.0) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 1544.0) {
                                                                if (x[0] <= 1494.5) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    if (x[1] <= 20.199999809265137) {
                                                                        if (x[1] <= 20.15999984741211) {
                                                                            if (x[1] <= 20.114999771118164) {
                                                                                if (x[1] <= 20.09000015258789) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    if (x[0] <= 1501.5) {
                                                                                        if (x[0] <= 1497.0) {
                                                                                            votes[2] += 1;
                                                                                        }

                                                                                        else {
                                                                                            votes[1] += 1;
                                                                                        }
                                                                                    }

                                                                                    else {
                                                                                        votes[1] += 1;
                                                                                    }
                                                                                }
                                                                            }

                                                                            else {
                                                                                if (x[1] <= 20.139999389648438) {
                                                                                    if (x[0] <= 1509.5) {
                                                                                        if (x[0] <= 1499.0) {
                                                                                            votes[1] += 1;
                                                                                        }

                                                                                        else {
                                                                                            votes[2] += 1;
                                                                                        }
                                                                                    }

                                                                                    else {
                                                                                        votes[1] += 1;
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    if (x[0] <= 1520.5) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[1] += 1;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[1] <= 20.18000030517578) {
                                                                                if (x[0] <= 1502.5) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                if (x[0] <= 1503.5) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 20.219999313354492) {
                                                                            if (x[0] <= 1532.5) {
                                                                                if (x[0] <= 1511.5) {
                                                                                    if (x[0] <= 1502.5) {
                                                                                        votes[2] += 1;
                                                                                    }

                                                                                    else {
                                                                                        if (x[0] <= 1506.5) {
                                                                                            if (x[0] <= 1503.5) {
                                                                                                votes[1] += 1;
                                                                                            }

                                                                                            else {
                                                                                                votes[1] += 1;
                                                                                            }
                                                                                        }

                                                                                        else {
                                                                                            votes[1] += 1;
                                                                                        }
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1528.0) {
                                                                                if (x[0] <= 1508.5) {
                                                                                    if (x[0] <= 1505.5) {
                                                                                        if (x[0] <= 1503.5) {
                                                                                            votes[1] += 1;
                                                                                        }

                                                                                        else {
                                                                                            votes[1] += 1;
                                                                                        }
                                                                                    }

                                                                                    else {
                                                                                        votes[2] += 1;
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1556.5) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    if (x[1] <= 20.139999389648438) {
                                                                        if (x[1] <= 20.09000015258789) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[0] <= 2617.5) {
                                                        if (x[0] <= 1581.5) {
                                                            if (x[1] <= 19.94499969482422) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            if (x[1] <= 19.975000381469727) {
                                                                if (x[1] <= 19.360000610351562) {
                                                                    if (x[0] <= 1979.5) {
                                                                        if (x[1] <= 18.5) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 2360.5) {
                                                                            if (x[1] <= 18.020000457763672) {
                                                                                if (x[1] <= 17.989999771118164) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[1] <= 17.96500015258789) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                if (x[0] <= 2545.5) {
                                                                                    if (x[0] <= 2542.5) {
                                                                                        if (x[1] <= 18.789999961853027) {
                                                                                            votes[1] += 1;
                                                                                        }

                                                                                        else {
                                                                                            votes[2] += 1;
                                                                                        }
                                                                                    }

                                                                                    else {
                                                                                        votes[2] += 1;
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    if (x[1] <= 18.394999504089355) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        if (x[1] <= 19.34000015258789) {
                                                                                            votes[1] += 1;
                                                                                        }

                                                                                        else {
                                                                                            if (x[0] <= 2612.5) {
                                                                                                votes[1] += 1;
                                                                                            }

                                                                                            else {
                                                                                                votes[1] += 1;
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[0] <= 2160.0) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 19.449999809265137) {
                                                                            if (x[0] <= 2612.0) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1599.5) {
                                                                    if (x[0] <= 1586.5) {
                                                                        if (x[0] <= 1584.5) {
                                                                            if (x[1] <= 20.06999969482422) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                if (x[1] <= 20.114999771118164) {
                                                                                    if (x[0] <= 1583.5) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[2] += 1;
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    if (x[0] <= 1583.5) {
                                                                                        votes[2] += 1;
                                                                                    }

                                                                                    else {
                                                                                        if (x[1] <= 20.139999389648438) {
                                                                                            votes[2] += 1;
                                                                                        }

                                                                                        else {
                                                                                            if (x[1] <= 20.170000076293945) {
                                                                                                votes[2] += 1;
                                                                                            }

                                                                                            else {
                                                                                                votes[2] += 1;
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1585.5) {
                                                                                if (x[1] <= 20.135000228881836) {
                                                                                    votes[2] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                if (x[1] <= 20.1899995803833) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 20.18000030517578) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[1] <= 20.219999313354492) {
                                                                                if (x[0] <= 1587.5) {
                                                                                    if (x[1] <= 20.199999809265137) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[2] += 1;
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    if (x[1] <= 20.199999809265137) {
                                                                                        votes[2] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[2] += 1;
                                                                                    }
                                                                                }
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[0] <= 2402.5) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 20.039999961853027) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 19.469999313354492) {
                                                            if (x[1] <= 17.989999771118164) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                if (x[0] <= 2646.5) {
                                                                    if (x[0] <= 2618.5) {
                                                                        if (x[1] <= 19.40499973297119) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[1] <= 19.43000030517578) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 18.010000228881836) {
                                                                            if (x[0] <= 2630.5) {
                                                                                if (x[0] <= 2628.5) {
                                                                                    votes[2] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[1] <= 18.114999771118164) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 2682.5) {
                                                                            if (x[0] <= 2648.5) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                if (x[0] <= 2656.5) {
                                                                                    votes[2] += 1;
                                                                                }

                                                                                else {
                                                                                    if (x[1] <= 18.829999923706055) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[2] += 1;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[1] <= 18.854999542236328) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                if (x[1] <= 19.05500030517578) {
                                                                                    votes[2] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }
                                                }
                                            }
                                        }

                                        else {
                                            if (x[0] <= 3477.0) {
                                                if (x[1] <= 20.270000457763672) {
                                                    if (x[0] <= 1504.5) {
                                                        if (x[0] <= 1487.0) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            if (x[0] <= 1503.5) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 1555.5) {
                                                            if (x[0] <= 1534.5) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[1] <= 24.109999656677246) {
                                                        if (x[0] <= 1169.5) {
                                                            if (x[1] <= 21.5600004196167) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                if (x[1] <= 22.394999504089355) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 1626.5) {
                                                                if (x[1] <= 21.03499984741211) {
                                                                    if (x[1] <= 20.289999961853027) {
                                                                        if (x[0] <= 1508.0) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1587.5) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1522.5) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1524.0) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[1] <= 21.505000114440918) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 2991.5) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    if (x[0] <= 2993.0) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 24.774999618530273) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[1] <= 23.44499969482422) {
                                                    votes[2] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }
                                    }

                                    else {
                                        if (x[0] <= 3904.0) {
                                            if (x[1] <= 23.5) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            if (x[1] <= 23.510000228881836) {
                                                if (x[1] <= 23.489999771118164) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #9
                        if (x[0] <= 301.5) {
                            if (x[0] <= 13.5) {
                                if (x[0] <= 9.5) {
                                    if (x[1] <= 21.015000343322754) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        else {
                            if (x[1] <= 17.079999923706055) {
                                if (x[0] <= 1185.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[1] <= 16.234999656677246) {
                                        if (x[1] <= 15.46500015258789) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            votes[2] += 1;
                                        }
                                    }

                                    else {
                                        if (x[0] <= 2023.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[1] <= 17.024999618530273) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[1] <= 20.199999809265137) {
                                    if (x[1] <= 17.789999961853027) {
                                        if (x[1] <= 17.75) {
                                            if (x[0] <= 1501.5) {
                                                if (x[1] <= 17.65999984741211) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    if (x[1] <= 17.72000026702881) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        if (x[0] <= 1491.5) {
                                                            if (x[0] <= 1447.5) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[0] <= 1549.0) {
                                                    if (x[1] <= 17.729999542236328) {
                                                        if (x[1] <= 17.710000038146973) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            if (x[0] <= 1534.0) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 1534.5) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }

                                        else {
                                            if (x[0] <= 1486.5) {
                                                if (x[0] <= 1418.5) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    votes[2] += 1;
                                                }
                                            }

                                            else {
                                                if (x[1] <= 17.770000457763672) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    if (x[0] <= 2083.0) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1] <= 18.114999771118164) {
                                            if (x[0] <= 2021.5) {
                                                if (x[0] <= 967.0) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    if (x[0] <= 1534.5) {
                                                        if (x[1] <= 17.8149995803833) {
                                                            if (x[0] <= 1410.5) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 17.84000015258789) {
                                                            if (x[1] <= 17.8149995803833) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 1564.0) {
                                                                if (x[1] <= 17.90000057220459) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    if (x[1] <= 18.039999961853027) {
                                                                        if (x[0] <= 1545.5) {
                                                                            if (x[1] <= 18.0) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[1] <= 18.010000228881836) {
                                                    if (x[1] <= 17.989999771118164) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        if (x[0] <= 2636.5) {
                                                            if (x[0] <= 2628.5) {
                                                                if (x[0] <= 2623.5) {
                                                                    if (x[0] <= 2411.0) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 2540.5) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }

                                        else {
                                            if (x[0] <= 2617.5) {
                                                if (x[0] <= 1237.0) {
                                                    if (x[1] <= 20.030000686645508) {
                                                        if (x[0] <= 1121.5) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            if (x[0] <= 1171.0) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                if (x[0] <= 1223.0) {
                                                                    if (x[1] <= 19.985000610351562) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        votes[2] += 1;
                                                    }
                                                }

                                                else {
                                                    if (x[0] <= 2611.5) {
                                                        if (x[0] <= 2608.5) {
                                                            if (x[0] <= 2542.5) {
                                                                if (x[1] <= 20.114999771118164) {
                                                                    if (x[1] <= 19.06999969482422) {
                                                                        if (x[1] <= 18.9399995803833) {
                                                                            if (x[0] <= 1896.0) {
                                                                                if (x[1] <= 18.449999809265137) {
                                                                                    votes[2] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 19.989999771118164) {
                                                                            if (x[1] <= 19.225000381469727) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1754.5) {
                                                                                if (x[0] <= 1599.5) {
                                                                                    if (x[1] <= 20.06999969482422) {
                                                                                        if (x[1] <= 20.010000228881836) {
                                                                                            if (x[0] <= 1483.5) {
                                                                                                votes[2] += 1;
                                                                                            }

                                                                                            else {
                                                                                                votes[1] += 1;
                                                                                            }
                                                                                        }

                                                                                        else {
                                                                                            if (x[0] <= 1489.0) {
                                                                                                if (x[1] <= 20.030000686645508) {
                                                                                                    votes[1] += 1;
                                                                                                }

                                                                                                else {
                                                                                                    votes[1] += 1;
                                                                                                }
                                                                                            }

                                                                                            else {
                                                                                                votes[1] += 1;
                                                                                            }
                                                                                        }
                                                                                    }

                                                                                    else {
                                                                                        if (x[1] <= 20.09000015258789) {
                                                                                            if (x[0] <= 1545.0) {
                                                                                                votes[1] += 1;
                                                                                            }

                                                                                            else {
                                                                                                if (x[0] <= 1585.5) {
                                                                                                    if (x[0] <= 1560.5) {
                                                                                                        votes[1] += 1;
                                                                                                    }

                                                                                                    else {
                                                                                                        if (x[0] <= 1572.0) {
                                                                                                            votes[2] += 1;
                                                                                                        }

                                                                                                        else {
                                                                                                            votes[2] += 1;
                                                                                                        }
                                                                                                    }
                                                                                                }

                                                                                                else {
                                                                                                    votes[1] += 1;
                                                                                                }
                                                                                            }
                                                                                        }

                                                                                        else {
                                                                                            if (x[0] <= 1512.5) {
                                                                                                if (x[0] <= 1496.0) {
                                                                                                    if (x[0] <= 1485.5) {
                                                                                                        votes[1] += 1;
                                                                                                    }

                                                                                                    else {
                                                                                                        votes[1] += 1;
                                                                                                    }
                                                                                                }

                                                                                                else {
                                                                                                    votes[1] += 1;
                                                                                                }
                                                                                            }

                                                                                            else {
                                                                                                if (x[0] <= 1572.5) {
                                                                                                    votes[2] += 1;
                                                                                                }

                                                                                                else {
                                                                                                    votes[1] += 1;
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[0] <= 1544.5) {
                                                                        if (x[0] <= 1494.5) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1501.5) {
                                                                                if (x[1] <= 20.139999389648438) {
                                                                                    if (x[0] <= 1498.5) {
                                                                                        votes[2] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[2] += 1;
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    if (x[0] <= 1498.5) {
                                                                                        votes[2] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[1] += 1;
                                                                                    }
                                                                                }
                                                                            }

                                                                            else {
                                                                                if (x[1] <= 20.15999984741211) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    if (x[0] <= 1525.0) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        if (x[1] <= 20.18000030517578) {
                                                                                            votes[1] += 1;
                                                                                        }

                                                                                        else {
                                                                                            votes[1] += 1;
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 20.18000030517578) {
                                                                            if (x[0] <= 1584.5) {
                                                                                if (x[0] <= 1568.0) {
                                                                                    votes[2] += 1;
                                                                                }

                                                                                else {
                                                                                    if (x[0] <= 1582.5) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        if (x[1] <= 20.15999984741211) {
                                                                                            votes[2] += 1;
                                                                                        }

                                                                                        else {
                                                                                            votes[1] += 1;
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }

                                                                            else {
                                                                                if (x[0] <= 1587.5) {
                                                                                    if (x[1] <= 20.15999984741211) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        if (x[0] <= 1586.5) {
                                                                                            votes[1] += 1;
                                                                                        }

                                                                                        else {
                                                                                            votes[1] += 1;
                                                                                        }
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                if (x[1] <= 19.360000610351562) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[1] <= 19.329999923706055) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 2614.5) {
                                                            if (x[1] <= 19.449999809265137) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 2616.5) {
                                                                if (x[1] <= 18.505000114440918) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[1] <= 19.43000030517578) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[1] <= 19.469999313354492) {
                                                    if (x[0] <= 2646.5) {
                                                        if (x[0] <= 2618.5) {
                                                            if (x[1] <= 19.40499973297119) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                if (x[1] <= 19.43000030517578) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    if (x[1] <= 19.449999809265137) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[1] <= 18.979999542236328) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                if (x[1] <= 19.079999923706055) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 18.854999542236328) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            if (x[0] <= 2728.0) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }
                                                    }
                                                }

                                                else {
                                                    votes[2] += 1;
                                                }
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[1] <= 23.510000228881836) {
                                        if (x[1] <= 21.81999969482422) {
                                            if (x[0] <= 1171.0) {
                                                if (x[1] <= 20.6850004196167) {
                                                    votes[2] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }

                                            else {
                                                if (x[0] <= 1553.5) {
                                                    if (x[1] <= 20.270000457763672) {
                                                        if (x[1] <= 20.244999885559082) {
                                                            if (x[0] <= 1347.0) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                if (x[1] <= 20.219999313354492) {
                                                                    if (x[0] <= 1501.5) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1502.5) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1506.5) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                if (x[0] <= 1532.5) {
                                                                                    if (x[0] <= 1515.0) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[2] += 1;
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[0] <= 1505.0) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1508.5) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1523.0) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 1504.5) {
                                                                if (x[0] <= 1502.0) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    if (x[0] <= 1503.5) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1531.0) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 21.0600004196167) {
                                                            if (x[0] <= 1552.5) {
                                                                if (x[1] <= 20.914999961853027) {
                                                                    if (x[1] <= 20.369999885559082) {
                                                                        if (x[0] <= 1520.0) {
                                                                            if (x[0] <= 1502.5) {
                                                                                if (x[1] <= 20.289999961853027) {
                                                                                    votes[2] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[1] <= 20.350000381469727) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 20.5) {
                                                                            if (x[1] <= 20.479999542236328) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                if (x[0] <= 1501.0) {
                                                                                    votes[2] += 1;
                                                                                }

                                                                                else {
                                                                                    if (x[0] <= 1523.0) {
                                                                                        votes[2] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[2] += 1;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[0] <= 1573.0) {
                                                        votes[2] += 1;
                                                    }

                                                    else {
                                                        if (x[0] <= 1579.0) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            if (x[1] <= 21.06999969482422) {
                                                                if (x[1] <= 20.219999313354492) {
                                                                    if (x[0] <= 1586.5) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1651.5) {
                                                                    if (x[0] <= 1613.0) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }

                                        else {
                                            if (x[0] <= 1078.5) {
                                                if (x[0] <= 814.0) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    if (x[1] <= 22.079999923706055) {
                                                        if (x[0] <= 848.5) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[1] <= 23.469999313354492) {
                                                    if (x[1] <= 23.360000610351562) {
                                                        votes[2] += 1;
                                                    }

                                                    else {
                                                        if (x[1] <= 23.380000114440918) {
                                                            if (x[0] <= 2403.0) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            if (x[1] <= 23.399999618530273) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }
                                                    }
                                                }

                                                else {
                                                    votes[2] += 1;
                                                }
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1] <= 24.81999969482422) {
                                            if (x[1] <= 24.010000228881836) {
                                                if (x[1] <= 23.989999771118164) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    if (x[0] <= 3312.0) {
                                                        if (x[0] <= 1049.5) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            votes[2] += 1;
                                        }
                                    }
                                }
                            }
                        }

                        // tree #10
                        if (x[1] <= 17.059999465942383) {
                            if (x[0] <= 1767.5) {
                                if (x[1] <= 16.31999969482422) {
                                    if (x[1] <= 8.5) {
                                        if (x[0] <= 358.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }

                                    else {
                                        if (x[0] <= 307.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[1] <= 13.5) {
                                                if (x[1] <= 11.5) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    if (x[0] <= 1093.5) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        votes[2] += 1;
                                                    }
                                                }
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[0] <= 858.5) {
                                        if (x[0] <= 298.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[1] <= 15.46500015258789) {
                                    votes[2] += 1;
                                }

                                else {
                                    if (x[1] <= 16.5) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }
                            }
                        }

                        else {
                            if (x[1] <= 20.18000030517578) {
                                if (x[1] <= 17.770000457763672) {
                                    if (x[1] <= 17.130000114440918) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        if (x[0] <= 1530.5) {
                                            if (x[0] <= 1432.0) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                if (x[1] <= 17.639999389648438) {
                                                    if (x[0] <= 1524.5) {
                                                        votes[2] += 1;
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }

                                                else {
                                                    if (x[1] <= 17.729999542236328) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        if (x[0] <= 1523.0) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }
                                                }
                                            }
                                        }

                                        else {
                                            if (x[1] <= 17.729999542236328) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                if (x[1] <= 17.75) {
                                                    if (x[0] <= 1551.5) {
                                                        if (x[0] <= 1534.5) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[0] <= 299.5) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[0] <= 1556.5) {
                                            if (x[0] <= 1089.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                if (x[0] <= 1215.0) {
                                                    if (x[1] <= 20.030000686645508) {
                                                        if (x[0] <= 1130.0) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }

                                                    else {
                                                        votes[2] += 1;
                                                    }
                                                }

                                                else {
                                                    if (x[0] <= 1460.0) {
                                                        if (x[0] <= 1258.0) {
                                                            if (x[1] <= 20.039999961853027) {
                                                                if (x[1] <= 19.890000343322754) {
                                                                    if (x[1] <= 19.704999923706055) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            if (x[1] <= 19.30500030517578) {
                                                                if (x[0] <= 1374.0) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1291.0) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 1482.5) {
                                                            if (x[0] <= 1471.5) {
                                                                if (x[1] <= 19.385000228881836) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[1] <= 18.889999389648438) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    if (x[0] <= 1474.5) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 1501.5) {
                                                                if (x[1] <= 18.440000534057617) {
                                                                    if (x[1] <= 17.860000610351562) {
                                                                        if (x[1] <= 17.789999961853027) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1487.5) {
                                                                                if (x[0] <= 1485.5) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[1] <= 20.09000015258789) {
                                                                        if (x[0] <= 1488.5) {
                                                                            if (x[1] <= 20.010000228881836) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 20.139999389648438) {
                                                                            if (x[0] <= 1494.5) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                if (x[0] <= 1496.0) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    if (x[0] <= 1497.5) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[1] += 1;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[1] <= 20.15999984741211) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                if (x[0] <= 1493.0) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                if (x[1] <= 18.449999809265137) {
                                                                    if (x[0] <= 1534.5) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1545.5) {
                                                                            if (x[1] <= 17.860000610351562) {
                                                                                if (x[1] <= 17.789999961853027) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    if (x[1] <= 17.8149995803833) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        if (x[1] <= 17.84000015258789) {
                                                                                            votes[2] += 1;
                                                                                        }

                                                                                        else {
                                                                                            votes[2] += 1;
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }

                                                                            else {
                                                                                if (x[1] <= 17.910000801086426) {
                                                                                    votes[2] += 1;
                                                                                }

                                                                                else {
                                                                                    if (x[1] <= 18.039999961853027) {
                                                                                        if (x[1] <= 18.010000228881836) {
                                                                                            votes[2] += 1;
                                                                                        }

                                                                                        else {
                                                                                            votes[2] += 1;
                                                                                        }
                                                                                    }

                                                                                    else {
                                                                                        votes[2] += 1;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[0] <= 1544.0) {
                                                                        if (x[0] <= 1503.5) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1508.5) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                if (x[1] <= 20.114999771118164) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    if (x[0] <= 1509.5) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        if (x[0] <= 1532.5) {
                                                                                            votes[1] += 1;
                                                                                        }

                                                                                        else {
                                                                                            votes[1] += 1;
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1555.5) {
                                                                            if (x[0] <= 1554.5) {
                                                                                if (x[0] <= 1553.5) {
                                                                                    if (x[1] <= 20.094999313354492) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[2] += 1;
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                if (x[1] <= 19.854999542236328) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }

                                        else {
                                            if (x[0] <= 2617.5) {
                                                if (x[1] <= 20.09000015258789) {
                                                    if (x[1] <= 18.020000457763672) {
                                                        if (x[1] <= 17.989999771118164) {
                                                            if (x[0] <= 1599.5) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 19.34000015258789) {
                                                            if (x[0] <= 2530.5) {
                                                                if (x[0] <= 2512.5) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            if (x[1] <= 19.55500030517578) {
                                                                if (x[0] <= 2612.5) {
                                                                    if (x[0] <= 2608.5) {
                                                                        if (x[0] <= 2096.0) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[1] <= 19.43000030517578) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                if (x[1] <= 19.770000457763672) {
                                                                    if (x[0] <= 2101.5) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[1] <= 20.010000228881836) {
                                                                        if (x[0] <= 1776.0) {
                                                                            if (x[1] <= 19.989999771118164) {
                                                                                if (x[0] <= 1584.5) {
                                                                                    if (x[1] <= 19.890000343322754) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        if (x[1] <= 19.920000076293945) {
                                                                                            if (x[0] <= 1583.5) {
                                                                                                votes[1] += 1;
                                                                                            }

                                                                                            else {
                                                                                                votes[1] += 1;
                                                                                            }
                                                                                        }

                                                                                        else {
                                                                                            votes[1] += 1;
                                                                                        }
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                if (x[0] <= 1596.5) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 20.06999969482422) {
                                                                            if (x[0] <= 1624.5) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1585.5) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[1] <= 20.139999389648438) {
                                                        if (x[0] <= 1587.5) {
                                                            if (x[1] <= 20.114999771118164) {
                                                                if (x[0] <= 1584.5) {
                                                                    if (x[0] <= 1574.5) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1585.5) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 20.15999984741211) {
                                                            if (x[0] <= 1585.0) {
                                                                if (x[0] <= 1564.0) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 1584.0) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                if (x[0] <= 1586.5) {
                                                                    if (x[0] <= 1585.5) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[1] <= 19.449999809265137) {
                                                    if (x[1] <= 18.010000228881836) {
                                                        if (x[1] <= 17.989999771118164) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            if (x[0] <= 2625.0) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 2646.5) {
                                                            if (x[0] <= 2638.5) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                if (x[0] <= 2639.5) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[1] <= 18.854999542236328) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                if (x[0] <= 2719.5) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    if (x[0] <= 2765.0) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[1] <= 19.469999313354492) {
                                                        votes[2] += 1;
                                                    }

                                                    else {
                                                        votes[2] += 1;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[0] <= 1165.0) {
                                    if (x[0] <= 309.0) {
                                        if (x[0] <= 14.5) {
                                            if (x[1] <= 21.015000343322754) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                if (x[0] <= 2.5) {
                                                    if (x[1] <= 21.59000015258789) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        votes[0] += 1;
                                                    }
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }

                                        else {
                                            if (x[0] <= 218.0) {
                                                if (x[1] <= 21.09000015258789) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    if (x[0] <= 77.5) {
                                                        if (x[1] <= 22.5) {
                                                            if (x[0] <= 68.5) {
                                                                votes[0] += 1;
                                                            }

                                                            else {
                                                                votes[0] += 1;
                                                            }
                                                        }

                                                        else {
                                                            votes[0] += 1;
                                                        }
                                                    }

                                                    else {
                                                        votes[0] += 1;
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[0] <= 223.0) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    votes[0] += 1;
                                                }
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1] <= 20.6850004196167) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            if (x[1] <= 22.545000076293945) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                if (x[0] <= 1037.0) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    votes[2] += 1;
                                                }
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[0] <= 3673.0) {
                                        if (x[1] <= 20.244999885559082) {
                                            if (x[0] <= 1545.5) {
                                                if (x[1] <= 20.199999809265137) {
                                                    if (x[0] <= 1347.5) {
                                                        votes[2] += 1;
                                                    }

                                                    else {
                                                        if (x[0] <= 1502.0) {
                                                            if (x[0] <= 1494.5) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                if (x[0] <= 1500.0) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[0] <= 1347.0) {
                                                        votes[2] += 1;
                                                    }

                                                    else {
                                                        if (x[0] <= 1512.0) {
                                                            if (x[1] <= 20.219999313354492) {
                                                                if (x[0] <= 1502.5) {
                                                                    if (x[0] <= 1490.5) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[0] <= 1503.5) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1503.5) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 1532.5) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                if (x[1] <= 20.219999313354492) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[1] <= 20.199999809265137) {
                                                    if (x[0] <= 1585.5) {
                                                        votes[2] += 1;
                                                    }

                                                    else {
                                                        if (x[0] <= 1588.0) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[1] <= 20.219999313354492) {
                                                        if (x[0] <= 1587.5) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }

                                                    else {
                                                        votes[2] += 1;
                                                    }
                                                }
                                            }
                                        }

                                        else {
                                            if (x[1] <= 24.09000015258789) {
                                                if (x[0] <= 1199.0) {
                                                    if (x[1] <= 20.80500030517578) {
                                                        votes[2] += 1;
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }

                                                else {
                                                    if (x[0] <= 1507.5) {
                                                        if (x[1] <= 20.289999961853027) {
                                                            if (x[0] <= 1501.5) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                if (x[0] <= 1504.5) {
                                                                    if (x[1] <= 20.270000457763672) {
                                                                        if (x[0] <= 1503.5) {
                                                                            if (x[0] <= 1502.5) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 1502.5) {
                                                                if (x[0] <= 1475.0) {
                                                                    if (x[1] <= 21.06999969482422) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1421.0) {
                                                                            if (x[0] <= 1301.5) {
                                                                                if (x[0] <= 1263.5) {
                                                                                    votes[2] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[1] <= 21.505000114440918) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1503.5) {
                                                                    if (x[1] <= 20.425000190734863) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[1] <= 20.764999389648438) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 3461.5) {
                                                            if (x[0] <= 1614.0) {
                                                                if (x[0] <= 1608.0) {
                                                                    if (x[1] <= 21.06999969482422) {
                                                                        if (x[0] <= 1587.5) {
                                                                            if (x[1] <= 20.270000457763672) {
                                                                                if (x[0] <= 1555.5) {
                                                                                    if (x[0] <= 1534.5) {
                                                                                        votes[2] += 1;
                                                                                    }

                                                                                    else {
                                                                                        if (x[0] <= 1544.0) {
                                                                                            votes[2] += 1;
                                                                                        }

                                                                                        else {
                                                                                            votes[1] += 1;
                                                                                        }
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[1] <= 20.3100004196167) {
                                                                                if (x[1] <= 20.270000457763672) {
                                                                                    votes[2] += 1;
                                                                                }

                                                                                else {
                                                                                    if (x[0] <= 1588.5) {
                                                                                        votes[2] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[2] += 1;
                                                                                    }
                                                                                }
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1559.0) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1575.5) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 2991.5) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    if (x[0] <= 2995.0) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 3596.0) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[1] <= 24.765000343322754) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    votes[2] += 1;
                                                }
                                            }
                                        }
                                    }

                                    else {
                                        if (x[0] <= 3834.5) {
                                            if (x[1] <= 23.05500030517578) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            if (x[1] <= 23.510000228881836) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #11
                        if (x[0] <= 299.5) {
                            if (x[1] <= 21.015000343322754) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[1] <= 21.699999809265137) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        else {
                            if (x[1] <= 17.059999465942383) {
                                if (x[0] <= 1211.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[0] <= 1780.5) {
                                        if (x[1] <= 14.734999656677246) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            if (x[1] <= 16.994999885559082) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                if (x[0] <= 1639.5) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    votes[0] += 1;
                                                }
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1] <= 15.46500015258789) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            if (x[1] <= 16.5) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                if (x[0] <= 2881.0) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    votes[2] += 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[0] <= 1114.0) {
                                    if (x[1] <= 22.545000076293945) {
                                        if (x[1] <= 20.609999656677246) {
                                            if (x[0] <= 953.5) {
                                                if (x[1] <= 19.975000381469727) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }

                                            else {
                                                if (x[1] <= 20.039999961853027) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    votes[2] += 1;
                                                }
                                            }
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }

                                    else {
                                        if (x[1] <= 23.5) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }

                                else {
                                    if (x[1] <= 20.219999313354492) {
                                        if (x[0] <= 1485.5) {
                                            if (x[0] <= 1207.5) {
                                                if (x[1] <= 18.925000190734863) {
                                                    if (x[0] <= 1182.0) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        votes[2] += 1;
                                                    }
                                                }

                                                else {
                                                    votes[2] += 1;
                                                }
                                            }

                                            else {
                                                if (x[1] <= 19.31999969482422) {
                                                    if (x[1] <= 17.789999961853027) {
                                                        if (x[0] <= 1446.5) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 1370.0) {
                                                            if (x[1] <= 17.875) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 1481.5) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                if (x[0] <= 1482.5) {
                                                                    if (x[1] <= 17.920000076293945) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[1] <= 17.860000610351562) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[0] <= 1218.5) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        if (x[1] <= 19.975000381469727) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            if (x[0] <= 1294.0) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                if (x[0] <= 1473.0) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    if (x[1] <= 20.030000686645508) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }

                                        else {
                                            if (x[1] <= 17.789999961853027) {
                                                if (x[1] <= 17.75) {
                                                    if (x[0] <= 1524.0) {
                                                        if (x[1] <= 17.335000038146973) {
                                                            votes[0] += 1;
                                                        }

                                                        else {
                                                            if (x[1] <= 17.704999923706055) {
                                                                if (x[0] <= 1497.0) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 17.710000038146973) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            if (x[0] <= 1552.0) {
                                                                if (x[0] <= 1534.5) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    if (x[1] <= 17.729999542236328) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[0] <= 1546.5) {
                                                        if (x[0] <= 1509.5) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            if (x[0] <= 1534.5) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[1] <= 18.139999389648438) {
                                                    if (x[1] <= 17.920000076293945) {
                                                        if (x[1] <= 17.880000114440918) {
                                                            if (x[0] <= 1834.0) {
                                                                if (x[1] <= 17.84000015258789) {
                                                                    if (x[1] <= 17.8149995803833) {
                                                                        if (x[0] <= 1525.0) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[1] <= 17.860000610351562) {
                                                                        if (x[0] <= 1487.5) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1532.5) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1534.5) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1546.0) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 1537.5) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 1593.5) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            if (x[1] <= 18.010000228881836) {
                                                                if (x[1] <= 17.989999771118164) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    if (x[0] <= 2717.5) {
                                                                        if (x[0] <= 2628.5) {
                                                                            if (x[0] <= 2420.5) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                if (x[0] <= 2540.5) {
                                                                                    votes[2] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[1] <= 19.449999809265137) {
                                                        if (x[0] <= 2646.5) {
                                                            if (x[1] <= 18.199999809265137) {
                                                                if (x[1] <= 18.18000030517578) {
                                                                    if (x[1] <= 18.15999984741211) {
                                                                        if (x[0] <= 2290.0) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 2530.5) {
                                                                    if (x[0] <= 2511.5) {
                                                                        if (x[0] <= 2400.5) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[1] <= 18.920000076293945) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[1] <= 19.34000015258789) {
                                                                        if (x[1] <= 18.394999504089355) {
                                                                            if (x[0] <= 2619.5) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 2638.5) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                if (x[1] <= 18.979999542236328) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 19.40499973297119) {
                                                                            if (x[1] <= 19.380000114440918) {
                                                                                if (x[0] <= 2614.5) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                if (x[0] <= 2614.5) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 2677.5) {
                                                                if (x[1] <= 18.864999771118164) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[1] <= 18.854999542236328) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    if (x[0] <= 2713.5) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 1776.0) {
                                                            if (x[0] <= 1553.5) {
                                                                if (x[0] <= 1503.5) {
                                                                    if (x[0] <= 1498.5) {
                                                                        if (x[0] <= 1494.5) {
                                                                            if (x[1] <= 20.030000686645508) {
                                                                                if (x[1] <= 20.010000228881836) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1496.0) {
                                                                                if (x[1] <= 20.114999771118164) {
                                                                                    if (x[1] <= 20.09000015258789) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[1] += 1;
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                if (x[0] <= 1497.5) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    if (x[1] <= 20.02999973297119) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[1] += 1;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 20.09000015258789) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1500.5) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                if (x[1] <= 20.199999809265137) {
                                                                                    if (x[0] <= 1501.5) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[1] += 1;
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    if (x[0] <= 1502.5) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[1] += 1;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[0] <= 1506.5) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 20.09000015258789) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[1] <= 20.199999809265137) {
                                                                                if (x[1] <= 20.114999771118164) {
                                                                                    if (x[0] <= 1519.5) {
                                                                                        if (x[0] <= 1512.5) {
                                                                                            votes[1] += 1;
                                                                                        }

                                                                                        else {
                                                                                            votes[1] += 1;
                                                                                        }
                                                                                    }

                                                                                    else {
                                                                                        votes[1] += 1;
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    if (x[1] <= 20.18000030517578) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        if (x[0] <= 1521.0) {
                                                                                            votes[1] += 1;
                                                                                        }

                                                                                        else {
                                                                                            votes[1] += 1;
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }

                                                                            else {
                                                                                if (x[0] <= 1532.5) {
                                                                                    if (x[0] <= 1517.5) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[2] += 1;
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                if (x[1] <= 20.139999389648438) {
                                                                    if (x[1] <= 20.06999969482422) {
                                                                        if (x[0] <= 1602.5) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1657.0) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1584.5) {
                                                                            if (x[1] <= 20.09000015258789) {
                                                                                if (x[0] <= 1572.0) {
                                                                                    votes[2] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                if (x[1] <= 20.114999771118164) {
                                                                                    if (x[0] <= 1574.5) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[2] += 1;
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1587.5) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[1] <= 20.199999809265137) {
                                                                        if (x[0] <= 1584.5) {
                                                                            if (x[0] <= 1561.5) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                if (x[1] <= 20.15999984741211) {
                                                                                    if (x[0] <= 1574.0) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[2] += 1;
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[1] <= 20.18000030517578) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                if (x[0] <= 1587.5) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1587.5) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 2510.0) {
                                                                if (x[1] <= 20.02999973297119) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[1] <= 19.469999313354492) {
                                                                    if (x[0] <= 2618.5) {
                                                                        if (x[0] <= 2617.5) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1] <= 23.489999771118164) {
                                            if (x[1] <= 20.270000457763672) {
                                                if (x[1] <= 20.244999885559082) {
                                                    if (x[0] <= 1528.0) {
                                                        if (x[0] <= 1508.0) {
                                                            if (x[0] <= 1503.5) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }

                                                    else {
                                                        votes[2] += 1;
                                                    }
                                                }

                                                else {
                                                    if (x[0] <= 1506.0) {
                                                        if (x[0] <= 1499.5) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            if (x[0] <= 1502.5) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                if (x[0] <= 1503.5) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 1546.0) {
                                                            if (x[0] <= 1534.5) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[1] <= 21.644999504089355) {
                                                    if (x[1] <= 21.015000343322754) {
                                                        if (x[1] <= 20.289999961853027) {
                                                            if (x[0] <= 1503.5) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }

                                                else {
                                                    if (x[0] <= 3991.5) {
                                                        if (x[1] <= 23.469999313354492) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }

                                                    else {
                                                        votes[2] += 1;
                                                    }
                                                }
                                            }
                                        }

                                        else {
                                            if (x[1] <= 24.81999969482422) {
                                                if (x[1] <= 24.010000228881836) {
                                                    if (x[0] <= 2967.0) {
                                                        votes[2] += 1;
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #12
                        if (x[1] <= 17.059999465942383) {
                            if (x[0] <= 1780.5) {
                                if (x[1] <= 16.234999656677246) {
                                    if (x[0] <= 303.5) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[0] <= 1210.5) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[2] += 1;
                                        }
                                    }
                                }

                                else {
                                    if (x[1] <= 16.994999885559082) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[1] <= 17.005000114440918) {
                                            if (x[0] <= 319.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[0] <= 2731.5) {
                                    votes[2] += 1;
                                }

                                else {
                                    if (x[1] <= 16.0) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }
                            }
                        }

                        else {
                            if (x[1] <= 20.114999771118164) {
                                if (x[1] <= 17.770000457763672) {
                                    if (x[1] <= 17.729999542236328) {
                                        if (x[0] <= 1524.5) {
                                            if (x[0] <= 1492.0) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                if (x[1] <= 17.639999389648438) {
                                                    if (x[0] <= 1506.5) {
                                                        votes[0] += 1;
                                                    }

                                                    else {
                                                        votes[2] += 1;
                                                    }
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }

                                        else {
                                            if (x[1] <= 17.710000038146973) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                if (x[0] <= 1552.0) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }
                                    }

                                    else {
                                        if (x[0] <= 1531.0) {
                                            if (x[0] <= 1431.0) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                if (x[0] <= 1509.5) {
                                                    if (x[0] <= 1480.5) {
                                                        votes[2] += 1;
                                                    }

                                                    else {
                                                        votes[2] += 1;
                                                    }
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }

                                        else {
                                            if (x[1] <= 17.75) {
                                                if (x[0] <= 1554.5) {
                                                    if (x[0] <= 1534.5) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[1] <= 18.114999771118164) {
                                        if (x[1] <= 17.989999771118164) {
                                            if (x[1] <= 17.84000015258789) {
                                                if (x[0] <= 1525.0) {
                                                    if (x[0] <= 1285.0) {
                                                        votes[2] += 1;
                                                    }

                                                    else {
                                                        if (x[1] <= 17.789999961853027) {
                                                            if (x[0] <= 1432.5) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[0] <= 2083.0) {
                                                        if (x[1] <= 17.8149995803833) {
                                                            if (x[1] <= 17.789999961853027) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[1] <= 17.920000076293945) {
                                                    if (x[1] <= 17.880000114440918) {
                                                        if (x[1] <= 17.860000610351562) {
                                                            if (x[0] <= 2083.0) {
                                                                if (x[0] <= 1486.5) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    if (x[0] <= 1493.5) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 2094.0) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 1793.5) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[0] <= 1914.0) {
                                                        votes[2] += 1;
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }
                                            }
                                        }

                                        else {
                                            if (x[1] <= 18.010000228881836) {
                                                if (x[0] <= 309.5) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    if (x[0] <= 1319.0) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        if (x[0] <= 2390.5) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            if (x[0] <= 2625.0) {
                                                                if (x[0] <= 2540.5) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[0] <= 1810.5) {
                                                    if (x[1] <= 18.030000686645508) {
                                                        if (x[0] <= 1532.5) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            if (x[0] <= 1545.0) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        votes[2] += 1;
                                                    }
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }
                                    }

                                    else {
                                        if (x[0] <= 301.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[1] <= 19.449999809265137) {
                                                if (x[1] <= 18.994999885559082) {
                                                    if (x[1] <= 18.15999984741211) {
                                                        if (x[1] <= 18.139999389648438) {
                                                            if (x[0] <= 1922.0) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 2294.0) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 1758.0) {
                                                            if (x[1] <= 18.729999542236328) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 2616.0) {
                                                                if (x[1] <= 18.394999504089355) {
                                                                    if (x[0] <= 2497.5) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[1] <= 19.005000114440918) {
                                                        if (x[0] <= 1275.0) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 19.34000015258789) {
                                                            if (x[0] <= 1916.0) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            if (x[1] <= 19.380000114440918) {
                                                                if (x[0] <= 2612.5) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 2614.5) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[1] <= 19.510000228881836) {
                                                    if (x[0] <= 2614.5) {
                                                        votes[2] += 1;
                                                    }

                                                    else {
                                                        if (x[1] <= 19.469999313354492) {
                                                            if (x[0] <= 2617.5) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[1] <= 19.809999465942383) {
                                                        if (x[1] <= 19.770000457763672) {
                                                            if (x[0] <= 2100.0) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 2099.5) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 19.96500015258789) {
                                                            if (x[1] <= 19.920000076293945) {
                                                                if (x[0] <= 2160.5) {
                                                                    if (x[0] <= 1205.0) {
                                                                        if (x[1] <= 19.860000610351562) {
                                                                            if (x[0] <= 1112.5) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[1] <= 19.899999618530273) {
                                                                                if (x[1] <= 19.880000114440918) {
                                                                                    if (x[0] <= 906.0) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[1] += 1;
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                if (x[0] <= 1015.5) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1585.5) {
                                                                            if (x[1] <= 19.899999618530273) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                if (x[0] <= 1583.5) {
                                                                                    votes[1] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 2154.5) {
                                                                    if (x[1] <= 19.940000534057617) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1158.0) {
                                                                            if (x[0] <= 901.5) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[1] <= 20.010000228881836) {
                                                                if (x[1] <= 19.989999771118164) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    if (x[0] <= 1619.0) {
                                                                        if (x[0] <= 1066.5) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1466.5) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                if (x[1] <= 20.09000015258789) {
                                                                    if (x[1] <= 20.06999969482422) {
                                                                        if (x[1] <= 20.050000190734863) {
                                                                            if (x[0] <= 1304.5) {
                                                                                if (x[1] <= 20.030000686645508) {
                                                                                    if (x[0] <= 1137.0) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[2] += 1;
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                if (x[1] <= 20.030000686645508) {
                                                                                    if (x[0] <= 2036.5) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[2] += 1;
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    if (x[0] <= 2140.0) {
                                                                                        if (x[0] <= 1556.5) {
                                                                                            if (x[0] <= 1533.0) {
                                                                                                votes[1] += 1;
                                                                                            }

                                                                                            else {
                                                                                                votes[1] += 1;
                                                                                            }
                                                                                        }

                                                                                        else {
                                                                                            votes[1] += 1;
                                                                                        }
                                                                                    }

                                                                                    else {
                                                                                        votes[2] += 1;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 2561.0) {
                                                                                if (x[0] <= 1557.5) {
                                                                                    votes[2] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1191.0) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1543.5) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                if (x[0] <= 1585.5) {
                                                                                    if (x[0] <= 1572.0) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[2] += 1;
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    votes[1] += 1;
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[0] <= 1246.5) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1512.5) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1586.0) {
                                                                                if (x[0] <= 1559.5) {
                                                                                    if (x[0] <= 1519.0) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        votes[1] += 1;
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    if (x[0] <= 1574.5) {
                                                                                        votes[1] += 1;
                                                                                    }

                                                                                    else {
                                                                                        if (x[0] <= 1584.5) {
                                                                                            votes[2] += 1;
                                                                                        }

                                                                                        else {
                                                                                            votes[2] += 1;
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[0] <= 1130.0) {
                                    if (x[1] <= 21.015000343322754) {
                                        if (x[0] <= 309.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[0] <= 712.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                if (x[1] <= 20.699999809265137) {
                                                    votes[2] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }
                                    }

                                    else {
                                        if (x[0] <= 311.5) {
                                            if (x[0] <= 19.5) {
                                                if (x[1] <= 21.59000015258789) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    votes[0] += 1;
                                                }
                                            }

                                            else {
                                                if (x[0] <= 207.5) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    if (x[1] <= 21.72000026702881) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        votes[0] += 1;
                                                    }
                                                }
                                            }
                                        }

                                        else {
                                            if (x[0] <= 1117.5) {
                                                if (x[0] <= 816.0) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    if (x[0] <= 829.0) {
                                                        votes[2] += 1;
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[1] <= 23.489999771118164) {
                                        if (x[0] <= 1512.0) {
                                            if (x[0] <= 1484.5) {
                                                if (x[0] <= 1145.5) {
                                                    if (x[1] <= 20.730000495910645) {
                                                        votes[2] += 1;
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }

                                                else {
                                                    if (x[1] <= 20.15999984741211) {
                                                        if (x[0] <= 1292.0) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 1214.0) {
                                                            if (x[1] <= 20.914999961853027) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                if (x[1] <= 21.47499942779541) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[1] <= 20.225000381469727) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                if (x[0] <= 1265.5) {
                                                                    if (x[1] <= 21.079999923706055) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[0] <= 1460.0) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1468.0) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[0] <= 1502.5) {
                                                    if (x[1] <= 20.300000190734863) {
                                                        if (x[0] <= 1494.5) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            if (x[0] <= 1498.5) {
                                                                if (x[0] <= 1496.0) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1501.5) {
                                                                    if (x[0] <= 1499.5) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        if (x[1] <= 20.199999809265137) {
                                                                            if (x[1] <= 20.170000076293945) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }

                                                                        else {
                                                                            votes[1] += 1;
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[1] <= 20.234999656677246) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 21.06999969482422) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            if (x[0] <= 1489.0) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[0] <= 1506.5) {
                                                        if (x[1] <= 20.270000457763672) {
                                                            if (x[1] <= 20.219999313354492) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                if (x[1] <= 20.244999885559082) {
                                                                    if (x[0] <= 1503.5) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[0] <= 1503.5) {
                                                                        votes[1] += 1;
                                                                    }

                                                                    else {
                                                                        votes[1] += 1;
                                                                    }
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[1] <= 20.545000076293945) {
                                                                if (x[1] <= 20.369999885559082) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 1508.0) {
                                                            if (x[1] <= 20.219999313354492) {
                                                                if (x[1] <= 20.199999809265137) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[1] += 1;
                                                                }
                                                            }

                                                            else {
                                                                if (x[1] <= 20.244999885559082) {
                                                                    votes[1] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[1] <= 20.244999885559082) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }

                                        else {
                                            if (x[1] <= 20.18000030517578) {
                                                if (x[1] <= 20.15999984741211) {
                                                    if (x[0] <= 1585.5) {
                                                        if (x[1] <= 20.139999389648438) {
                                                            if (x[0] <= 1545.5) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                if (x[0] <= 1575.5) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 1544.5) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }

                                                else {
                                                    if (x[0] <= 1577.5) {
                                                        if (x[0] <= 1544.0) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 1586.5) {
                                                            if (x[0] <= 1585.5) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[0] <= 3991.5) {
                                                    if (x[1] <= 20.219999313354492) {
                                                        if (x[0] <= 1544.5) {
                                                            if (x[0] <= 1532.5) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 1589.5) {
                                                                if (x[0] <= 1586.5) {
                                                                    votes[2] += 1;
                                                                }

                                                                else {
                                                                    if (x[0] <= 1587.5) {
                                                                        votes[2] += 1;
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 23.469999313354492) {
                                                            if (x[0] <= 1553.5) {
                                                                if (x[0] <= 1544.0) {
                                                                    if (x[0] <= 1528.0) {
                                                                        if (x[1] <= 21.0600004196167) {
                                                                            if (x[0] <= 1522.5) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                if (x[1] <= 20.395000457763672) {
                                                                                    votes[2] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }
                                                                        }

                                                                        else {
                                                                            if (x[0] <= 1519.0) {
                                                                                votes[2] += 1;
                                                                            }

                                                                            else {
                                                                                votes[1] += 1;
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1534.5) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[1] <= 20.270000457763672) {
                                                                                if (x[1] <= 20.244999885559082) {
                                                                                    votes[2] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    if (x[1] <= 20.5) {
                                                                        if (x[1] <= 20.339999198913574) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            votes[2] += 1;
                                                                        }
                                                                    }

                                                                    else {
                                                                        votes[2] += 1;
                                                                    }
                                                                }
                                                            }

                                                            else {
                                                                if (x[0] <= 1626.5) {
                                                                    if (x[0] <= 1610.0) {
                                                                        if (x[0] <= 1585.5) {
                                                                            votes[2] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[1] <= 20.8149995803833) {
                                                                                if (x[1] <= 20.289999961853027) {
                                                                                    if (x[1] <= 20.270000457763672) {
                                                                                        votes[2] += 1;
                                                                                    }

                                                                                    else {
                                                                                        if (x[0] <= 1587.5) {
                                                                                            votes[2] += 1;
                                                                                        }

                                                                                        else {
                                                                                            if (x[0] <= 1588.5) {
                                                                                                votes[1] += 1;
                                                                                            }

                                                                                            else {
                                                                                                votes[2] += 1;
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }

                                                                            else {
                                                                                if (x[1] <= 21.885000228881836) {
                                                                                    votes[2] += 1;
                                                                                }

                                                                                else {
                                                                                    votes[2] += 1;
                                                                                }
                                                                            }
                                                                        }
                                                                    }

                                                                    else {
                                                                        if (x[0] <= 1615.5) {
                                                                            votes[1] += 1;
                                                                        }

                                                                        else {
                                                                            if (x[1] <= 21.905000686645508) {
                                                                                votes[1] += 1;
                                                                            }

                                                                            else {
                                                                                votes[2] += 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }

                                                                else {
                                                                    votes[2] += 1;
                                                                }
                                                            }
                                                        }

                                                        else {
                                                            if (x[0] <= 2990.0) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }
                                                    }
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1] <= 24.010000228881836) {
                                            if (x[0] <= 2967.0) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                if (x[1] <= 23.510000228881836) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    if (x[0] <= 3462.0) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }
                                            }
                                        }

                                        else {
                                            if (x[0] <= 3042.0) {
                                                if (x[1] <= 25.5) {
                                                    votes[2] += 1;
                                                }

                                                else {
                                                    votes[2] += 1;
                                                }
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // return argmax of votes
                        uint8_t classIdx = 0;
                        float maxVotes = votes[0];

                        for (uint8_t i = 1; i < 3; i++) {
                            if (votes[i] > maxVotes) {
                                classIdx = i;
                                maxVotes = votes[i];
                            }
                        }

                        return classIdx;
                    }

                protected:
                };
            }
        }
    }