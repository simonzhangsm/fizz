/*
 *  Copyright (c) 2018-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <fizz/extensions/javacrypto/JavaCryptoPeerCert.h>
#include <fizz/protocol/Factory.h>

namespace fizz {

/**
 * This class instantiates objects using Java Crypto API instead of OpenSSL.
 */
class JavaCryptoFactory : public Factory {
 public:
  ~JavaCryptoFactory() override = default;

  std::shared_ptr<PeerCert> makePeerCert(Buf certData) const override {
    if (certData->empty()) {
      throw std::runtime_error("empty peer cert");
    }

    return std::make_unique<JavaCryptoPeerCert>(std::move(certData));
  }
};
} // namespace fizz
