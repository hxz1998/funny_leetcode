/**
 * Created by Xiaozhong on 2020/10/3.
 * Copyright (c) 2020/10/3 Xiaozhong. All rights reserved.
 */

class ParkingSystem {
private:
    int _big, _medium, _small;
public:
    ParkingSystem(int big, int medium, int small) : _big(big), _medium(medium), _small(small) {

    }

    bool addCar(int carType) {
        switch (carType) {
            case 1:
                return _big <= 0 ? false : _big--;
            case 2:
                return _medium <= 0 ? false : _medium--;
            case 3:
                return _small <= 0 ? false : _small--;
        }
        return false;
    }
};