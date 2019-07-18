/* Copyright 2019 Danny Nguyen <danny@keeb.io>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | Knob 1: Vol Dn/Up |      | Knob 2: Page Dn/Up |
        | Press: Mute       | Home | Press: Play/Pause  |
        | Hold: Layer 2     | Up   | RGB Mode           |
        | Git push current branch? | Git pull | Git fetch              |
     */
    [0] = LAYOUT(
        KC_MUTE, QMKBEST, BL_TOGG,
        MO(1)  , KC_UP  , AEM_START_AUTHOR,
        KC_LEFT, KC_DOWN, KC_RGHT
    ),
    /*
        | RESET          | Held: Layer 2 | Hold: Layer 3 |
        | Start AEM Author | Start AEM Publish | Oak Compaction?   |
        | Maven Build AEM Author | Maven Build AEM Publish  | Maven run tests? |
     */
    [1] = LAYOUT(
        RESET  , ______, , MO(2)
        AEM_START_AUTHOR, AEM_START_PUBLISH, RGB_MOD,
        MVN_BUILD_AEM_AUTHOR, MVN_BUILD_AEM_PUBLISH , KC_MNXT
    ),
    /*
        | RESET          | Held: Layer 2 | Held: Layer 3 |
        || Backlight Step | Backlight Toggle | RGB Mode   |
        | Media Previous | End  | Media Next |
     */
    [2] = LAYOUT(
        RESET  , ______, ______,
        BL_STEP, BL_TOGG, RGB_MOD,
        KC_MPRV, KC_END , KC_MNXT
    ),

    // Maybe add a layer for npm/grunt/gulp commands?
};

enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;

    case AEM_START_AUTHOR:
      // Start AEM Author instance with debugging
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("blah blah blah" SS_TAP(X_ENTER));
        backlight_toggle();
      } else {
        backlight_toggle();
      }
      break;

    case AEM_START_PUBLISH:
      // Start AEM Author instance with debugging
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("blah blah blah PUBLISH" SS_TAP(X_ENTER));
        backlight_toggle();
      } else {
        backlight_toggle();
      }
      break;

    case MVN_BUILD_AEM_AUTHOR:
      // Start AEM Author instance with debugging
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("mvn clean install -e -PautoInstallPackage" SS_TAP(X_ENTER));
        backlight_toggle();
      } else {
        backlight_toggle();
      }
      break;

    case MVN_BUILD_AEM_PUBLISH:
      // Start AEM Author instance with debugging
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("mvn clean install -e -PautoInstallPackagePublish" SS_TAP(X_ENTER));
        backlight_toggle();
      } else {
        backlight_toggle();
      }
      break;
  }
  return true;
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}
