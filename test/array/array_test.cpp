#include "../../source/array/array.h"
#include "../catch.hpp"
#include <array>

SCENARIO("array can be constructed",
	 "[construction][array]"){

  GIVEN("size greater then 0"){

    WHEN("default constructed"){
      THEN("it constructs properly"){
	REQUIRE_NOTHROW( (tc::array<int,2>()) );
      }
    }

    WHEN("constucted with initializer list smaller then the array size"){
      THEN("it constructs properly"){
	REQUIRE_NOTHROW( (tc::array<int,2>{1}) );
      }
    }

    WHEN("constucted with initializer list with the same size as the array"){
      THEN("it constructs properly"){
	REQUIRE_NOTHROW( (tc::array<int,2>{1,2}) );
      }
    }

    WHEN("constucted with initializer list bigger then the array size"){
      THEN("it throws invalid_argument exception"){
	REQUIRE_THROWS_AS( (tc::array<int,2>{1,2,3}) , std::invalid_argument );
      }
    }
  }

  GIVEN("size equal to 0"){

    WHEN("default constructed"){
      THEN("it constructs properly"){
	REQUIRE_NOTHROW( (tc::array<int,0>()) );
      }
    }

    WHEN("constucted with empty initializer list"){
      THEN("it constructs properly"){
	REQUIRE_NOTHROW( (tc::array<int,0>{}) );
      }
    }

    WHEN("constucted with non-empty initializer list"){
      THEN("it throws invalid_argument exception"){
	REQUIRE_THROWS_AS( (tc::array<int,0>{1}) , std::invalid_argument );
      }
    }
  }

}
