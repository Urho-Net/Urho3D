# macOS Library Setup Instructions

## Important: Remove Quarantine Attribute

When you download these libraries from GitHub, macOS automatically adds a quarantine attribute that prevents them from being loaded, even though they are properly code-signed.

### Quick Fix (Required before first use):

Run this command in the directory where you extracted the libraries:

```bash
xattr -dr com.apple.quarantine DotNet/libs/macos
```

Or use the provided script from the repository root:

```bash
./script/remove_quarantine_macos.sh
```

### Why This Happens:

- **The libraries ARE properly code-signed** during the build process
- macOS adds the quarantine attribute to **all files downloaded from the internet**
- This is a security feature and cannot be disabled in the build workflow
- The quarantine blocks the library even though the signature is valid

### Verification:

After removing the quarantine, you can verify the libraries are properly signed:

```bash
codesign -dvv DotNet/libs/macos/arm64/Release/libUrho3D.dylib
codesign -dvv DotNet/libs/macos/x86_64/Release/libUrho3D.dylib
```

You should see:
```
Signature=adhoc
```

### Alternative: One-Time Permission

If you prefer not to remove the quarantine, you can grant permission per-application:
1. Try to run your application
2. When blocked, go to System Settings → Privacy & Security
3. Click "Allow Anyway" for the specific library
4. Try running again and click "Open" when prompted

**Note**: The quick fix command is faster and removes the need to do this for every application.
